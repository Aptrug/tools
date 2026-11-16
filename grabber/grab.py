#!/usr/bin/python3
import argparse, atexit, itertools, subprocess, sys, time, urllib.request
from pathlib import Path
from playwright.sync_api import sync_playwright, TimeoutError as PWTimeout

here = Path(__file__).resolve().parent  # chapters go here: <novel-slug>/
brave = Path.home() / ".local/share/brave_origin/brave_origin/brave"
port = 9222
cache = Path.home() / "goinfre/playwright_cache"  # Brave profile + log

ap = argparse.ArgumentParser(
	description="Download novel chapters as .txt files via a real Brave session.",
	epilog="examples:\n  ./grab.py              chapter 1 up to the last one\n  ./grab.py 5            chapter 5\n  ./grab.py 11 20        chapters 11-20",
	formatter_class=argparse.RawDescriptionHelpFormatter,
)
ap.add_argument("first", nargs="?", type=int, help="first chapter (default: 1)")
ap.add_argument(
	"last",
	nargs="?",
	type=int,
	help="last chapter (default: same as first; with no args, goes on until a chapter is missing)",
)
ap.add_argument(
	"--novel",
	default="shadow-slave",
	help="novel slug in the URL (default: %(default)s)",
)
ap.add_argument(
	"-f",
	"--force",
	action="store_true",
	help="re-download chapters that already exist",
)
ap.add_argument(
	"--min",
	type=int,
	default=5,
	help="skip pages with fewer paragraphs than this, e.g. error pages (default: %(default)s)",
)
args = ap.parse_args()

if args.first is None:
	first, last = 1, None  # None = keep going until a chapter is missing
else:
	first, last = (
		args.first,
		args.last if args.last is not None else args.first,
	)
if first < 1 or (last is not None and last < first):
	ap.error("chapter range must satisfy 1 <= first <= last")
if not brave.is_file():
	sys.exit(f"Brave binary not found: {brave}")

base = f"https://asurascans.com/novels/{args.novel}/chapter/"
profile = cache / "profile"
outdir = here / args.novel  # e.g. shadow-slave/
log = cache / "brave.log"
cdp = f"http://127.0.0.1:{port}"
js = r"els => els.filter(e => !e.closest('nav,header,footer,aside,#comments-section')).map(e => e.innerText.replace(/\s+/g, ' ').trim()).filter(Boolean)"

outdir.mkdir(exist_ok=True)
cache.mkdir(parents=True, exist_ok=True)
if (
	last is not None
	and not args.force
	and all(
		(outdir / f"chapter_{n:04d}.txt").exists()
		for n in range(first, last + 1)
	)
):
	sys.exit(
		"nothing to do, all chapters already downloaded (--force to redo)"
	)
chapters = itertools.count(first) if last is None else range(first, last + 1)

try:
	urllib.request.urlopen(cdp + "/json/version", timeout=1)
	print("reusing running brave", flush=True)
except OSError:
	print("starting brave...", flush=True)
	cmd = [
		str(brave),
		f"--user-data-dir={profile}",
		f"--remote-debugging-port={port}",
		"--no-first-run",
		"--no-default-browser-check",
		"about:blank",
	]
	proc = subprocess.Popen(
		cmd,
		stdout=subprocess.DEVNULL,
		stderr=open(log, "w"),
		start_new_session=True,
	)
	atexit.register(
		proc.terminate
	)  # close brave when the script ends, even on errors
	for _ in range(60):
		try:
			urllib.request.urlopen(cdp + "/json/version", timeout=1)
			break
		except OSError:
			if proc.poll() is not None:
				sys.exit(
					f"brave exited early (another instance on the profile?), see {log}"
				)
			time.sleep(0.5)
	else:
		sys.exit(f"brave never opened the debug port, see {log}")

with sync_playwright() as p:
	browser = p.chromium.connect_over_cdp(cdp)
	ctx = browser.contexts[0]
	page = ctx.pages[0] if ctx.pages else ctx.new_page()
	routed = False
	for n in chapters:
		out = outdir / f"chapter_{n:04d}.txt"
		if out.exists() and not args.force:
			continue
		print(
			f"chapter {n}: loading (click the Cloudflare checkbox if shown)...",
			flush=True,
		)
		page.goto(base + str(n), wait_until="domcontentloaded")
		page.wait_for_function(
			"!document.title.includes('Just a moment')",
			polling=500,
			timeout=120000,
		)
		try:
			page.wait_for_selector("p")
			paras = page.eval_on_selector_all("p", js)
		except PWTimeout:
			paras = []
		if (
			f"/chapter/{n}" not in page.url
		):  # redirected elsewhere (e.g. the novel's page): no such chapter
			paras = []
		if len(paras) < args.min:
			print(
				f"chapter {n}: only {len(paras)} paragraphs (--min {args.min}) at {page.url}, skipped",
				flush=True,
			)
			if last is None:
				print("no more chapters, stopping", flush=True)
				break
			continue
		tmp = out.with_suffix(
			".tmp"
		)  # write aside, then rename: out is never half-written
		tmp.write_text("\n\n".join(paras) + "\n", encoding="utf-8")
		tmp.replace(out)
		print(f"chapter {n}: {len(paras)} paragraphs saved", flush=True)
		if (
			not routed
		):  # after the first page is through, skip images/fonts/media
			page.route(
				"**/*",
				lambda r: (
					r.abort()
					if r.request.resource_type
					in ("image", "font", "media")
					else r.continue_()
				),
			)
			routed = True
		time.sleep(1)

print(f"done, files in {outdir}")

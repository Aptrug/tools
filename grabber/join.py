#!/usr/bin/python3
import argparse, os, sys
from pathlib import Path

here = Path(__file__).resolve().parent  # the joined file is written here

ap = argparse.ArgumentParser(
	description="Join downloaded chapter files into one .txt file.",
	epilog="examples:\n  ./join.py shadow-slave                 all chapters, 1 to the last one present\n"
	"  ./join.py shadow-slave -a 15 -b 100    chapters 15-100 -> shadow-slave-0015-0100.txt\n"
	"  ./join.py shadow-slave -a 50           chapter 50 to the end",
	formatter_class=argparse.RawDescriptionHelpFormatter,
)
ap.add_argument(
	"dir", type=Path, help="directory holding chapter_NNNN.txt files"
)
ap.add_argument(
	"-a",
	type=int,
	default=1,
	metavar="FIRST",
	help="first chapter (default: 1)",
)
ap.add_argument(
	"-b",
	type=int,
	metavar="LAST",
	help="last chapter (default: the highest one in the directory)",
)
ap.add_argument(
	"-o", action="store_true", help="open the result in vim -R when done"
)
args = ap.parse_args()

if not args.dir.is_dir():
	sys.exit(f"not a directory: {args.dir}")

first = args.a
if args.b is not None:
	last = args.b
else:
	have = [
		int(f.stem[8:])
		for f in args.dir.glob("chapter_*.txt")
		if f.stem[8:].isdigit()
	]
	if not have:
		sys.exit(f"no chapter files in {args.dir}")
	last = max(have)
if first < 1 or last < first:
	ap.error(f"bad range {first}-{last} (need 1 <= a <= b)")

name = args.dir.resolve().name
out = here / f"{name}-{first:04d}-{last:04d}.txt"
parts, missing = [], []
for n in range(first, last + 1):
	f = args.dir / f"chapter_{n:04d}.txt"
	if f.is_file():
		parts.append(
			"CHAPTER %04d {{{\n%s\n}}}\n"
			% (n, f.read_text(encoding="utf-8").strip())
		)
	else:
		missing.append(n)

if missing:
	sys.exit(
		f"{len(missing)} chapter(s) missing in {args.dir}, nothing written: "
		+ ", ".join(map(str, missing[:10]))
		+ (" ..." if len(missing) > 10 else "")
	)
out.write_text("\n".join(parts), encoding="utf-8")
for old in (
	here.iterdir()
):  # earlier outputs of this novel: <name>-<digits>-<digits>.txt
	if (
		old == out
		or old.suffix != ".txt"
		or not old.name.startswith(name + "-")
	):
		continue
	a, _, b = old.stem[len(name) + 1 :].partition("-")
	if a.isdigit() and b.isdigit():
		old.unlink()
		print(f"removed old {old.name}")
print(f"wrote {out} ({len(parts)} chapters)", flush=True)
if args.o:
	try:
		os.execvp(
			"vim", ["vim", "-R", str(out)]
		)  # replaces this process, no shell
	except FileNotFoundError:
		sys.exit("vim not found in PATH")

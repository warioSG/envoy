from flask import Flask
from flask import request
import socket
import os
import sys
import requests

app = Flask(__name__)

TRACE_HEADERS_TO_PROPAGATE = [
    'X-Ot-Span-Context',
    'X-Request-Id',
    'X-B3-TraceId',
    'X-B3-SpanId',
    'X-B3-ParentSpanId',
    'X-B3-Sampled',
    'X-B3-Flags'
]

@app.route('/v1/certs/list/approved')
def approved():
    return ('{"certificates":[{"fingerprint_sha256":"5D:1A:FB:90:4A:4D:F8:42:41:B8:24:4A:1C:1A:9B:00:2C:B0:64:A7:E3:BE:10:3B:8D:B5:7A:3C:AE:E2:21:89"}]}'+"\n")

if __name__ == "__main__":
    app.run(host='0.0.0.0', port=8002, debug=True)

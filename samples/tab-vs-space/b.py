#!/usr/bin/env python

MAX = 100

import logging
logging.basicConfig(level=logging.DEBUG)
logger = logging.getLogger(__name__)

flags = [True] * MAX
primes = []
for idx in xrange(2, MAX):
    if not flags[idx]:
        continue
    primes.append(idx)
    for nonprime in xrange(idx, MAX, idx):
        flags[nonprime] = False
		logger.info(flags)

print primes

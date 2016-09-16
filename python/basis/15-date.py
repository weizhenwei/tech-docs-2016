#!/usr/bin/env python

import time
import calendar

ticks = time.time()
print "Current time:", ticks

localtime = time.localtime(ticks)
print "Current time:", localtime


structtime = time.asctime(localtime)
print "Current time:", structtime

print time.strftime("%Y-%m-%d %H:%M:%S", localtime)


cal = calendar.month(2016, 9)
print cal


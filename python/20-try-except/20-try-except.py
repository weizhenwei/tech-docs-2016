#!/usr/bin/env python
# -*- coding: UTF-8 -*-

try:
    fh = open("a.txt", "w")
    fh.write("Hello, world")
except IOError:
    print "Error: No such file or directory"
else:
    print "Write succeed!"
    fh.close()


# finally
try:
    fh = open("a.txt", "w")
    fh.write("Hello, world")
except IOError:
    print "Error: No such file or directory"
else:
    print "Write succeed!"
    fh.close()
finally:
    print "This will always be printed"


#raise
def mye(level):
    if level < 1:
        raise Exception("Invalid level!", level)

try:
    mye(0)
except "Invalid level!":
    print 1
else:
    print 2


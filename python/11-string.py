#!/usr/bin/env python

import math

var1 = "Hello"
var2 = "Worldpress"

print "var1 = ", var1
print "var2 = ", var2
print "var1[0] = ", var1[0]
print "var2[1:5] = ", var2[1:5]

if ('H' in var1):
    print "H is in var1 ", var1
else:
    print "H is not in var1 ", var1


if ('H' not in var2):
    print "H is not in var2 ", var2
else:
    print "H is in var2 ", var2


var3 = var1 + var2;
print "var1 + var2 = ", var3

print "var1 = %s, var2 = %s" % (var1, var2)


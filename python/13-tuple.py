#!/usr/bin/env python

import math

tuple = ('physics', 'chemistry', 1997, 2001)

print "tuple[2] = ", tuple[2]
print "tuple[1:3] = ", tuple[1:3]

print "length of delete:", len(tuple)

if ('physics' in tuple):
    print "physics is in tuple"
else:
    print "physics is not in tuple"


for elem in tuple:
    print "elem :", elem

tuple2 = ("334", "dfsdf", "adg")

tuple3 = tuple + tuple2
for elem in tuple3:
    print "elem :", elem



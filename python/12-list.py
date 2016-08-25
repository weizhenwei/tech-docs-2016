#!/usr/bin/env python

import math

list = ['physics', 'chemistry', 1997, 2001];

print "list[2] = ", list[2]
print "list[1:3] = ", list[1:3]

list[2] = "math";


print "update, list[2] = ", list[2]

del list[2]
print "delete, list[2] = ", list[2]

print "length of delete:", len(list)

if ('physics' in list):
    print "physics is in list"
else:
    print "physics is not in list"


for elem in list:
    print "elem :", elem


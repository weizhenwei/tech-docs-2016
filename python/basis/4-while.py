#!/usr/bin/env python

count = 0
while (count < 9):
    print "The count is ", count
    count = count + 1


count = 0
while (count < 9):
    if (count % 2 == 0):
        count = count + 1
        continue

    print "The count is ", count
    count = count + 1

count = 0
while (count < 9):
    if (count == 7):
        break

    print "The count is ", count
    count = count + 1


count = 0
while (count < 9):
    print "The count is ", count
    count = count + 1
else:
    print "The count is more than 9"


print "Good bye!"



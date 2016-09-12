#!/usr/bin/env python


# raw_input a text line
sstr = raw_input("Please input:")
print "Your input is:", sstr

# input a text line
# eexpr = input("Please input:")
# print "Your input is:", eexpr

# open and close file
fileobj = open("a.txt", "w", 0)
print "filename", fileobj.name
print "closed", fileobj.closed
print "access mode", fileobj.mode
print "softspace", fileobj.softspace
fileobj.write("Hello, world!\n")
fileobj.close()


fileobj = open("a.txt", "r", 0)
print "filename", fileobj.name
print "closed", fileobj.closed
print "access mode", fileobj.mode
print "softspace", fileobj.softspace
sstr = fileobj.read();
print "read file:", sstr
fileobj.close()


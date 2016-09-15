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


# tell
fileobj = open("a.txt", "r", 0)
sstr = fileobj.read(10)
print "read file:", sstr
position = fileobj.tell()
print "current position:", position
fileobj.seek(0, 0)
sstr = fileobj.read(10)
print "read file again:", sstr
position = fileobj.tell()
print "current position again:", position


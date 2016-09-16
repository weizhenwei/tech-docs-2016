#!/usr/bin/env python
# -*- coding: UTF-8 -*-


counter = 100
miles = 1000.0
name = "Jone"

print counter
print miles
print name


# test string
str = "Hello, world!"
print str
print str[0]
print str[2:5]
print str[2:]
print str + "Test"


# test list
list = ["abcd", 123, 3.234, "Jone", 90.23]
tinylist = ["abcd", 123]
print list
print list[0]
print list[1:3]
print list[2:]
print list * 2
print list + tinylist


# test tuple
tuple = ("abcd", 123, 3.234, "Jone", 90.23)
tinytuple = ("abcd", 123)
print tuple
print tuple[0]
print tuple[1:3]
print tuple[2:]
print tuple * 2
print tuple + tinytuple

# test dictionary

dict = {}
dict["one"] = 1
dict[2] = "two" 
tinydict = {"name" : "Jone", "code" : 1234, "dept" : "sales"}
print dict
print dict["one"]
print dict[2]
print tinydict
print tinydict.keys()
print tinydict.values()


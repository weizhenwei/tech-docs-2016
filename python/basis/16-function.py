#!/usr/bin/env python


def printme(str):
    "print something input"
    print str
    return

printme("Hello")


def changeme(list):
    list.append([1, 2, 3, 4])
    print "In the function, list = ", list
    
    return



list = [23, 34, 32, 12]
print "Out the function, before call list = ", list
changeme(list)
print "Out the function, after call list = ", list


# keyword parameter
def printinfo(name, age):
    "print out the name and age"
    print "Name:", name
    print "Age:", age

    return

printinfo(age = 50, name = "Mike")
printinfo(name = "Kay", age = 45)



# default parameter
def printinfo(name, age = 28):
    "print out the name and age"
    print "Name:", name
    print "Age:", age

    return

printinfo(name = "Kay")


# variable parameter
def printinfo(name, *rest_parameters):
    "print out the name and age"
    print "Name:", name
    for var in rest_parameters:
        print var

    return

printinfo("Kay", 12, "female")


# lambda expression
sum = lambda arg1, arg2: arg1 + arg2
print "1 + 1 = ", sum(1, 1)



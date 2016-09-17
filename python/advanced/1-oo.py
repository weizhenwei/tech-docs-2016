#!/usr/bin/env python
# -*- coding: UTF-8 -*-


#define class
class Employee:
    empCount = 0

    def __init__(self, name, salary):
        self.name = name
        self.salary = salary
        Employee.empCount += 1

    def displayCount(self):
        print "Total employee %d" % Employee.empCount

    
    def displayEmployee(self):
        print "Name:", self.name, "Salary:", self.salary


# create object
emp1 = Employee("Zara", 2000)
emp2 = Employee("Hanni", 3000)


emp1.displayEmployee()
emp2.displayEmployee()
emp2.displayCount()
print "Total employee %d" % Employee.empCount


# access attribute
if (hasattr(emp1, "age")):
    print "Age is ", getattr(emp1, "age")
else:
    setattr(emp1, "age", 19)

if (hasattr(emp1, "age")):
    print "Age is ", getattr(emp1, "age")
    delattr(emp1, "age")
else:
    setattr(emp1, "age", 19)


# built-in attribute
print "Employee.__doc__:", Employee.__doc__
print "Employee.__name__:", Employee.__name__
print "Employee.__module__:", Employee.__module__
print "Employee.__bases__:", Employee.__bases__
print "Employee.__dict__:", Employee.__dict__


# gc
class Point:
    def __init__(self, x = 0, y = 0):
        self.x = x
        self.y = y

    def __del__(self):
        class_name = self.__class__.__name__
        print class_name, "destroyed"


p1 = Point(1, 2)
p2 = p1
p3 = p1
print id(p1), id(p2), id(p3)
del p1
del p2
del p3


class Parent:
    parentAttr = 100
    def __init__(self):
        print "Call Parent constructor"

    def parentMethod(self):
        print "Call Parent Method"

    def setAttr(self, attr):
        self.parentAttr = attr

    def getAttr(self):
        print "parent attribute:", Parent.parentAttr


class Child(Parent):
    def __init__(self):
        print "Call Child Constructor"

    def childMethod(self):
        print "Call Child Method"

c = Child()
c.childMethod()
c.parentMethod()
c.setAttr(1000)
c.getAttr()


# override
class Vector:
    def __init__(self, a, b):
        self.a = a
        self.b = b

    def __str__(self):
        return 'Vector (%d, %d)' % (self.a, self.b)
    
    def __add__(self, other):
        return Vector(self.a + other.a, self.b + other.b)
    
    
v1 = Vector(2, 10)
v2 = Vector(5, -2)
print v1 + v2


# private attribute and method, with prefix __, eg, __foo
class JusCounter:
    __secretCount = 0  # private attribute
    publicCount = 0    # public attribute

    def __count(self):
        print self.__secretCount

    def count(self):
        self.__secretCount += 1
        self.publicCount += 1
        self.__count()


counter = JusCounter()
counter.count()
counter.count()
print counter.publicCount


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



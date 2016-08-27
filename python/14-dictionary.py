#!/usr/bin/env python


Alice = {"Name": "Alice", "Age": 18, "Height": 180}
print "Alice['Name']:", Alice["Name"]
print "Alice['Age']:", Alice["Age"]
print "Alice['Height']:", Alice["Height"]

Alice["Age"] += 1
Alice["Height"] += 2
print "Alice['Name']:", Alice["Name"]
print "Alice['Age']:", Alice["Age"]
print "Alice['Height']:", Alice["Height"]


del Alice["Height"]
print "Alice['Name']:", Alice["Name"]
print "Alice['Age']:", Alice["Age"]
# deleted is not accessbil;
# print "Alice['Height']:", Alice["Height"]
Alice.clear()
del Alice



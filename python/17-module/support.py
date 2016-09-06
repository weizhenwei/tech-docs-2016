#!/usr/bin/env python


def printme(str):
    "print something input"
    print str
    return

def printmemore(str):
    "print something input"
    print "hehe, ", str
    return

if __name__ == "__main__":
    print "called by runing support"
    printmemore("self")
else:
    print "called from import"
    printmemore("import")


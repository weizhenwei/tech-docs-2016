#!/usr/bin/env python


import support
support.printme("Hello, World")
support.printmemore("Hello, World")


# from support import printmemore
# from support import *
# # no module name prefix
# printme("Hello, World")
# printmemore("Hello, World")


# global variable
Money = 2000
def AddMoney():
    global Money
    Money = Money + 1

print Money
AddMoney()
print Money

import math
content = dir(math)
print content


# locals and globals
def AddMultipleMoney():
    local = locals()
    print "locals:", local
    gglobal = globals()
    print "globals:", gglobal

AddMultipleMoney()


#reload
reload(support)


#!/usr/bin/env python
#-*- coding=utf-8 -*-

# from pack1 import mymodule1
# from pack2 import mymodule2
mymodule1.function1()
mymodule2.function2()

import pack1.mymodule1
import pack2.mymodule2
pack1.mymodule1.function1()
pack2.mymodule2.function2()


if __name__ == "__main__":
    print "main running as main program"
else:
    print "main initializing"



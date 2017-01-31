#!/bin/bash

set -x
set -e

gcc -g -c extern_c.c 

ar rcs libextern_c.a extern_c.o
ranlib libextern_c.a
g++ -g main.cpp -L. -lextern_c

# g++ -g main.cpp extern_c.o



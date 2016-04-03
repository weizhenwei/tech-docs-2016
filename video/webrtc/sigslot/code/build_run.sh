#!/bin/bash

g++ -g -std=c++11 -c sigslot.cc
g++ -g -std=c++11 test.cc sigslot.o

./a.out

rm sigslot.o a.out


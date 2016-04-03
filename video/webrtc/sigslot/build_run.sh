#!/bin/bash

g++ -g -std=c++11 -c sigslot.cc
g++ -g -std=c++11 test.cpp sigslot.o

rm sigslot.o
./a.out
rm a.out


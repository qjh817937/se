#!/bin/bash

rm *.o

g++  -g -c -I./ Dictionary.cpp -o Dictionary.o

g++  -g -c -I./ PostlistFile.cpp -o PostlistFile.o

g++  -g -c -I./ InvertedIndex.cpp -o InvertedIndex.o

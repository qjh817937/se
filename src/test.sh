#!/bin/bash

#rm *.o

g++  -g -c -I./ Dictionary.cpp -o Dictionary.o

g++  -g -c -I./ PostlistFile.cpp -o PostlistFile.o

g++  -g -c -I./ InvertedIndex.cpp -o InvertedIndex.o

#g++  -g -c -I./ Doc.cpp -o Doc.o

#g++  -g -c -I./ DocidManager.cpp -o DocidManager.o

g++  -g -c -I./ IndexWriter.cpp -o IndexWriter.o

#g++  -g -c -I./ AttributeWriter.cpp -o AttributeWriter.o
g++  -g -c -I./ Int32AttributeWriter.cpp -o Int32AttributeWriter.o

g++ -g -c -I./ main.cpp -o main.o

g++ -g `ls *.o` -o exe

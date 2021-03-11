#!/bin/bash

rm -f pathfinder
clang -c src/*.c
mkdir -p obj
mv *.o obj       
clang -o pathfinder obj/*.o -L./libmx -lmx
rm -rf obj/*.o
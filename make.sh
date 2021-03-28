#!/bin/bash

rm -f pathfinder
clang -g -std=c11 -Wall -Werror -Wextra -Wpedantic -c src/*.c
mkdir -p obj
mv *.o obj       
clang -g -std=c11 -Wall -Werror -Wextra -Wpedantic -o pathfinder obj/*.o -L./libmx -lmx
rm -rf obj/*.o
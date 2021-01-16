#!/bin/sh

clear
make

echo "\nOutput : "
gcc -Wall -Wextra -Werror main.c libftprintf.a
./a.out
rm a.out
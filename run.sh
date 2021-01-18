#!/bin/sh

clear
make

echo Output :
gcc -Wall -Wextra -Werror main.c libftprintf.a
./a.out
rm a.out
#!/bin/sh

make dbg;

echo  "\033[32;1mTEST Erreur : 1\033[0m"
valgrind ./zappy_server -p 90 -x 10 -y 10 -n toto titi -c 10 -t 10
echo "\033[32;1mTEST Erreur : 2\033[0m"
valgrind ./zappy_server -p  -x  -y  -n  -c 10 -t 10
echo "\033[32;1mTEST Erreur : 3\033[0m"
valgrind ./zappy_server -p 9090  -x 0  -y 0 -n  -c -12
echo "TEST 1"
valgrind ./zappy_server -p 4242 -x 40 -y 40 -n toto titi -c 10 -t 10
echo "TEST 1"
make clean

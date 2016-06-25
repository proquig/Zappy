#!/bin/bash

make dbg;


echo  "\033[32;1mTEST Erreur : 1\033[0m"
valgrind ./zappy_server -p 90 -x 10 -y 10 -n toto titi -c 10 -t 10
echo "\033[32;1mTEST Erreur : 2\033[0m"
valgrind ./zappy_server -p  -x  -y  -n  -c 10 -t 10
echo "\033[32;1mTEST Erreur : 3\033[0m"
valgrind ./zappy_server -p 9090  -x 0  -y 0 -n  -c -12
echo "TEST 1"
if [ -z $3 ]; then
    valgrind ./zappy_server -p 4242 -x $1 -y $2 -n toto titi -c 100 -t 100
else
    valgrind ./zappy_server -p 4242 -x $1 -y $2 -n toto titi -c 100 -t 10 & 2>toto
fi
echo "TEST 1"
make clean

i=0
while [ $i -lt $3 ]; do
    ../client/zappy_ai toto 4240 0 > /dev/null 2>&1 &
    i=$[$i+1]
done

#!/bin/sh

make re;
echo "TEST 1"
valgrind ./zappy_server -p 9090 -x 10 -y 10 -n toto titi -c 10 -t 10
echo "./zappy_server -p 9090 -x 10 -y 10 -n toto titi -c 10 -t 10"
#valgrind ./zappy_server -p 9090 -x 10 -y 10 -n toto titi -c 10 -t 10
#./zappy_server -p  -x  -y  -n  -c 10 -t 10
#valgrind ./zappy_server -p  -x  -y  -n  -c 10 -t 10
#./zappy_server -p 9090 -x 10 -y 10 -n toto titi -c 10 -t 10
#./zappy_server -p 9090 -x 10 -y 10 -n toto titi -c 10 -t 10
#./zappy_server -p 9090 -x 10 -y 10 -n toto titi -c 10 -t 10
#./zappy_server -p 9090 -x 10 -y 10 -n toto titi -c 10 -t 10

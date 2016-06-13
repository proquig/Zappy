#!/bin/sh

./zappy_server -p 9090 -x 10 -y 10 -n toto titi -c 10 -t 10
valgrind ./server -p 9090 -x 10 -y 10 -n toto titi -c 10 -t 10
./zappy_server -p  -x  -y  -n  -c 10 -t 10
valgrind ./server -p  -x  -y  -n  -c 10 -t 10
./zappy_server -p 9090 -x 10 -y 10 -n toto titi -c 10 -t 10
./zappy_server -p 9090 -x 10 -y 10 -n toto titi -c 10 -t 10
./zappy_server -p 9090 -x 10 -y 10 -n toto titi -c 10 -t 10
./zappy_server -p 9090 -x 10 -y 10 -n toto titi -c 10 -t 10

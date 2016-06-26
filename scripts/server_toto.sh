#!/bin/bash

i=0
while [ $i -lt $1 ]; do
    ../client/zappy_ai toto $2 163.172.28.139 > toto 2>1 &
#    i=$[$i+1]
done

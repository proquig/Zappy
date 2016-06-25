#!/bin/bash

i=0
while [ $i -lt $1 ]; do
    ../client/zappy_ai titi 4240 163.172.28.139 > titi 2>1 &
    i=$[$i+1]
done

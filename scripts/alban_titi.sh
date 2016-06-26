#!/bin/bash

i=0
while [ $i -lt $1 ]; do
    ../client/zappy_ai titi 4242 0 > titi 2>1 &
    i=$[$i+1]
done

#!/bin/bash

i=0
while [ $i -lt $1 ]; do
    ../client/zappy_ai toto 4240 10.29.125.205 > toto 2>1 &
    i=$[$i+1]
done

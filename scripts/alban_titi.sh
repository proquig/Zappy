#!/bin/bash

echo "TEST $1 client with team titi and port: $2"
i=0
while [ $i -lt $1 ]; do
    ../client/zappy_ai titi $2 10.29.125.205 > titi 2>1 &
    i=$[$i+1]
done

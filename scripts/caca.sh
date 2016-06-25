#!/bin/bash

i=0
while [ $i -lt $1 ]; do
    ../client/zappy_ai caca 4242 localhost > caca 2>1 &
    i=$[$i+1]
done

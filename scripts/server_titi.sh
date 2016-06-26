#!/bin/bash

i=0
while [ $i -lt $1 ]; do
    ../zappy_ai titi $2 163.172.28.139 > titi 2>1 &
    i=$[$i+1]
done

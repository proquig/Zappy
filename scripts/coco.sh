#!/bin/bash

i=0
while [ $i -lt $1 ]; do
    ../client/zappy_ai coco 4242 localhost > coco 2>1 &
    i=$[$i+1]
done

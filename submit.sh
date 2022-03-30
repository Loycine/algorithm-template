#!/bin/bash

while true; do
    python gen.py > input
    ./c1 < input > output1
    ./c2 < input > output2
    diff output1 output2
    if [ "$?" -ne 0 ] ; then 
    echo WA
    break;
    else 
    printf AC
    fi
done
#!/bin/bash
inputFront="input_"
inputMid="_"
inputEnd=".txt"
params=$@
size=$#
output="Davison_Andrew_executionTime.txt"
if [ $# == 0 ]; then
    for n in "10" "100" "1000";
    do
        for m in {1..25};
        do
            #echo "$inputFront$n$inputMid$m$inputEnd" $output
            ./a.out "$inputFront$n$inputMid$m$inputEnd" $output
        done
    done
else
    #echo ${params[0]}
    ./a.out ${params[0]}
fi
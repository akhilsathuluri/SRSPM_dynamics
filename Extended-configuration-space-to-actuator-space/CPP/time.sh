#!/bin/bash 
 
for i in {1..200} 
do 
        /usr/bin/time -f "%e" ./a &>> inverse.csv 
done 


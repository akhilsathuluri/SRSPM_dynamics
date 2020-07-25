#!/bin/bash 
 
for i in {1..1000} 
do 
        /usr/bin/time -f "%e" ./a &>> linsolvedd.csv 
done 


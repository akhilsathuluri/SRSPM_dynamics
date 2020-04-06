#!/bin/bash

for i in {1..10}
do
#	/usr/bin/time -f "%e" Configuration-space/CPP/./a &>> Configuration-space/CPP/exectime.csv
	TIMEFORMAT='%3R'time Configuration-space/CPP/./a &>> Configuration-space/CPP/exectime.csv
done


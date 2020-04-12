#!/bin/bash

for i in {1..1000}
do
	/usr/bin/time -f "%e" Configuration-space/CPP/./a &>> Config_exectime.csv

	/usr/bin/time -f "%e" Extended-configuration-space-to-actuator-space/CPP/./a &>> Extended_act_exectime.csv


	/usr/bin/time -f "%e" Extended-configuration-space-to-task-space/CPP/./a &>> Extended_task_exectime.csv


	/usr/bin/time -f "%e" Task-space/CPP/./a &>> task_exectime.csv
	
	/usr/bin/time -f "%e" 6_RSS/CPP/./a &>> 6rss_exectime.csv
done


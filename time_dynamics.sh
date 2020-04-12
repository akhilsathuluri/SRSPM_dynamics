#!/bin/bash

for i in {1..1000}
do
	/usr/bin/time -f "%e" Configuration-space/CPP/./a &>> config_exectime.csv
	
done

for i in {1..1000}
do
	/usr/bin/time -f "%e" Actuator-space/CPP/./a &>> act_exectime.csv
	
done

for i in {1..1000}
do
	/usr/bin/time -f "%e" Extended-configuration-space-to-actuator-space/CPP/./a &>> extended_act_exectime.csv
	
done

for i in {1..1000}
do
	/usr/bin/time -f "%e" Extended-configuration-space-to-task-space/CPP/./a &>> extended_task_exectime.csv
	
done

for i in {1..1000}
do
	/usr/bin/time -f "%e" Task-space/CPP/./a &>> task_exectime.csv
	
done
	
for i in {1..1000}
do
	/usr/bin/time -f "%e" 6_RSS/CPP/./a &>> 6rss_exectime.csv
	
done

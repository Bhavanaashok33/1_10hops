#!/bin/sh
n=0;
while [ $n -lt 10000 ]
do
basetime=$(date +%s%N)
read line
#sudo ifconfig eth1 10$line
echo "$(echo "scale=3; ($(date +%s%N) - ${basetime})/(1000000)" |bc)" >>timebash1.txt
n=$((n+1));
done<testRandomization.txt 

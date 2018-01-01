#!/bin/bash 
filename='output.text'
while read -r line; 
do
basetime=$(date +%s%N)
id=$(echo $line | head -c6); 
#./lfsr "${id}" 
#echo $id;   #code for passing id to other script file as parameter
echo "runtime: $(echo "scale=3; ($(date +%s%N) - ${basetime})/(1000000)" |bc) microseconds" >>timebash1.txt
done < "$filename"




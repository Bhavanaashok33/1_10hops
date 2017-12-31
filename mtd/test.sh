#!/bin/bash 
filename='output.text'
while read -r line; 
do
id=$(echo $line | head -c6); 
./lfsr "${id}" 
#echo $id;   #code for passing id to other script file as parameter 
done < "$filename"

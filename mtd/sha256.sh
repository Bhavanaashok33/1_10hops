#!bin/bash
n=0;
while [ $n -lt 4 ];
do
while read line
do
echo $line | sha256sum >> output.text;
foo=$(head -c 6 output.text)
#var5="$((16#foo))"
var1=$((0x${foo}))
echo 10$var1
n=$((n+1))
done
done <output.text 


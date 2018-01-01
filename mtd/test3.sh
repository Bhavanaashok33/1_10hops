#!/bin/bash
basetime=$(date +%s%N)
sleep 1
#ls -R /etc > /tmp/x
#rm -f /tmp/x
echo "runtime: $(echo  "scale=3;($(date +%s%N) - ${basetime})/(1000000)" |bc) seconds"
#END=$(date +%s)
#DIFF=$(($END - $START))
#echo "it took $DIFF seconds"

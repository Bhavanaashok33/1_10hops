n=0;
while [ $n -lt 10000 ];
do
./ping;
n=$((n+1));
done

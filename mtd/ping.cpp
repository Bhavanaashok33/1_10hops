#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<sys/time.h>
#include<string.h>
#include<fstream>
#include<unistd.h>
int main(){
FILE *myfile;
myfile=fopen("16_ping.txt","a");
clock_t t;
t=clock();
system("ping 10.10.15.1 -c 1");
t=clock()-t;
double time_taken=((double)t)/CLOCKS_PER_SEC;
fprintf(myfile, "%f" ,time_taken);
fprintf(myfile,"\n");
printf("%f \n",time_taken);
return 0;
}



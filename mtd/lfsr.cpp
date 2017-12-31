#include <stdlib.h>
#include <sys/time.h>
#include <stdint.h>
#include <time.h>
#include <stdio.h>
#include<string.h>
#include<fstream>
#include<unistd.h>
#include<stdint.h>
#include<iostream>
using namespace std;
void convertDectoHex(char output[],int ip_addr[]) {       
int i,newArr[6],k,ctr;     
for ( i=0; i<6; i++) {         
newArr[i] = 0;         
switch(output[i]) {             
case 'A': newArr[i]=10;                 
break;             
case 'B': newArr[i]=11;                 
break;             
case 'C': newArr[i]=12;                 
break;             
case 'D': newArr[i]=13;                 
break;             
case 'E': newArr[i]=14;                 
break;             
case 'F': newArr[i]=15;                 
break;             
default: newArr[i] = int(output[i])-48;        
 }    
 } 
int j=3; 
ctr = j;     
for (i=0; i<6; i++) {         
for (k=0; k<4; k++) {             
ip_addr[j] = newArr[i] %2;             
newArr[i] /= 2;             
j--;             
ctr++;         
}         
j=ctr;     
}          
i=0;     
int arr[3];        
char result[6];     
for (k=0;k<3; k++) {         
ctr = 128;         
arr[k] = 0;                
for (int j=0; j<8; j++) {             
arr[k] += ip_addr[i]*ctr;             
ctr /=2;             
i++;       
  }     
}
printf("%d.%d.%d",arr[2],arr[1],arr[0]);
//char string[15];

system("ping 10.10.2.2 -c 1");
}

int main(int argc,char *argv[] )
{
//int i = 0;     
//for (i = 0; i < argc; i++) 
//{         
//printf("argv[%d] = %s\n", i, argv[i]);    
//}
int ip_addr[24];
char output[6];
unsigned long int period=0;
FILE *myfile;
myfile=fopen("hashtime_2.txt", "a");
//clock_t t;
//t=clock();


char buffer[30];
//wall time

struct timeval tv;
time_t curtime;
gettimeofday(&tv,NULL);
curtime=tv.tv_sec;
strftime(buffer,30,"%T.",localtime(&curtime));
//printf("%s%ld\n",buffer,tv.tv_usec);


int clockcycle=0;
do{
do{
//struct timeval tv;                                                                                               
//time_t curtime;                                                                                                  
//gettimeofday(&tv,NULL);                                                                                          
//curtime=tv.tv_sec;                                                                                               
//strftime(buffer,30,"%T.",localtime(&curtime));                                                                   
//printf("%s%ld\n",buffer,tv.tv_usec); 

//char string[100];
                                                                       //snprintf(string, 100, "#!bin/bash read line echo $line | sha256sum>>line.txt echo $n n=$((n+1)) done <line.txt");
//system(string);
for(int i=0; i<argc; i++){
sprintf(output,"%s",argv[i]);
}
//printf("%s\n",output);
//char buffer2[230];                                                                                               
//struct timeval tv2;                                                                                              
//time_t curtime2;                                                                                                 
//gettimeofday(&tv2,NULL);                                                                                         
//curtime2=tv2.tv_sec;                                                                                           
convertDectoHex(output,ip_addr);
++period;
}
while(period!=1);
//printf("period cycle %d : %lu \n",clockcycle+1,period);
period=0;
clockcycle ++;
}
while(clockcycle!=1);

//t=clock()-t;
//double time_taken =((double)t)/CLOCKS_PER_SEC;
//fprintf(myfile,"%f", time_taken);
//fprintf(myfile,"\n");
//printf("%f \n", time_taken);
char buffer2[230];
struct timeval tv2;
time_t curtime2;
gettimeofday(&tv2,NULL);
curtime2=tv2.tv_sec;
strftime(buffer2,30,"%T.",localtime(&curtime2));
//printf("%s%ld seconds\n",buffer2,tv2.tv_usec);
//printf("%f\n",float(tv2.tv_usec-tv.tv_usec)/1000);
fprintf(myfile,"%f seconds", float(tv2.tv_usec-tv.tv_usec)/1000);
fprintf(myfile,"\n");
return 0;
}





































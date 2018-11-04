#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ifttt.h"
int main(int argc, char *argv[])
{
 FILE *fd;
 int n,y,high,low,first;
 char buf[101];
 char *temp;
 time_t start = time(NULL);
 int next = start+1;
 first =0;
 while(start < next){
 if((fd = fopen("/sys/bus/w1/devices/28-0213133656aa/w1_slave", "r")) == (FILE *)NULL) {
 perror("open of test.text failed");
 (void) exit(1);
 }
 n = fread(buf, 1, 100, fd);
 if(n == 0) {
 perror("read fails!");
 exit(1);
 }
 buf[n] = '\0';
 fprintf(stdout, "Read '%s'\n",buf+69);
 (void) fclose(fd);
 temp = buf+69;
 printf("Temp: %s",temp);
 y = atoi(temp);
 printf("Integer Y: %d\n",y);
 if(first == 0){
	low = y;
	high = y;
	first =1;
	}
 else{
	if(y <low){low = y;}
	else if(y>high){high = y;}
	}
 printf("High: %d Current: %d Low: %d\n",high,y,low);
 start = time(NULL);
 next = start+1;
}
 return 0;
}

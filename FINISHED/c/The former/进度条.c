#include <stdio.h>
#include <unistd.h>
int main(void){
	  int i;
     for (i=0; i<=100; i++)
     {
     	printf("percent complete: %3d%%\r",i);
     	sleep(100);
     }
     system("pause");
     return 0;
}
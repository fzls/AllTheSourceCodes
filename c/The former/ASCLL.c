#include <stdio.h>
#include <time.h>
int main(void){
     int i,j;
     printf("ASCLL\n");
     for(i=0;i<=31;i++){
     	for(j=0;j<=3;j++)
      printf("%3d->%3c  ",4*i+j,4*i+j);
      printf("\n");
      sleep(100);
   }
     system("pause");
     return 0;
}
#include <stdio.h>
int main(){
   int speed;
   scanf("%d",&speed);
   if(speed<=60)
   	printf("Speed: %d - %s\n",speed,"OK");
   else
     printf("Speed: %d - %s\n",speed,"Speeding");
}
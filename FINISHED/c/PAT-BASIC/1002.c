#include <stdio.h>
#include <math.h>
void yin( int digit){
	switch(digit){
	   case 0 : printf("ling");break;
	   case 1 : printf("yi");break;
	   case 2 : printf("er");break;
	   case 3 : printf("san");break;
	   case 4 : printf("si");break;
	   case 5 : printf("wu");break;
	   case 6 : printf("liu");break;
	   case 7 : printf("qi");break;
	   case 8 : printf("ba");break;
	   case 9 : printf("jiu");break;
	   
	   default:;
	}
	
	
	
	}
int main(){
   char s[100];
   int sum = 0, i, temp, count = 0 ;
   gets(s);
   for(i = 0; s[i] != 0; i++)
      sum += s[i] - '0';
   
   temp = sum;
   while(temp > 0){
   	++ count;
   	temp /= 10;
   	}
   
   while(count > 0){
   	yin( sum / (int)pow(10, count - 1)  %10 );
   	if(count > 1)
   		printf(" ");
   	count --;
   	}	
   
   system("pause");
       
}
#include <stdio.h>
int main(){
   int n, digit_B, digit_S, digit, i;
   
   scanf("%d",&n);
   digit = n % 10;
   digit_S = n / 10 % 10;
   digit_B = n / 100;
   
   while(digit_B--){
   	printf("B");
   	}
   while(digit_S--){
   	printf("S");
   	}	
   for(i = 1; i <= digit; i++)
   printf("%d",i);
   	
}
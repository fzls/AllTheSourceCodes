#include <stdio.h>
int main(){
   int n, i;
   scanf("%d",&n);
   if( (n/100) != 0 ){
   	for(i = 1; i <= n/100%10; i++)
   	printf("B");
   	}
   if( (n/10) != 0){
   	for(i = 1; i <= n/10%10; i++)
   	printf("S");
   	}	
   for(i = 1; i <= n%10; i++)
      printf("%d", i);
   system("pause");
      	
}
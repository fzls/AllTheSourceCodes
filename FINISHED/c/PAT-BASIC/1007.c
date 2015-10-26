#include <stdio.h>
#include <math.h>
int prime( int n){
	int i, limit;
	limit = (int) sqrt ( n ) + 1 ;
	for(i = 2; i < limit; i++)
	if(n % i == 0)
		return 0;
	
	return 1;	
	}
int main(){
   int n, i, j, pri[100000], count;
   scanf("%d",&n);
   j = 0;
   for(i = 2; i <= n; i++)
      if(prime(i))
      	pri[j++] = i;
   pri[j] = -1;
   
   count = 0;
   for(i = 1; pri[i] != -1; i++) 
   if(pri[i] - pri[i - 1] == 2)
   	count++;
   
   printf("%d\n",count);
   
   	  	
}
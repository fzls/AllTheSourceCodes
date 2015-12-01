#include "stdio.h"
#include "math.h"
int f(int n);
int main(void)
{
    int count=0, i, j, k, m, n, number;

    scanf("%d%d", &m, &n);
    if(m % 2 != 0) m = m + 1;
    if(m >= 6){
    	for (number=m; number<=n; number+=2){
    		j=1;
    		for (i=3; i<=number/2; i+=2){
    			if(f(i)==1&&f(number-i)==1){
    		   printf("%2d=%2d+%2d ", number, i, number - i);	
    		 count++;
    		   if(count%5==0)
    		  printf("\n");
    		  j=0;
    		  }
    		  if(j==0)
    		  	break;
    		  }
    		 }
    }
    system("pause");
}
int f(int n){
	int result=1,i;
	for(i=2;i<n;i++)
	if (n%i==0) 
		result=0;
	return result;
	}
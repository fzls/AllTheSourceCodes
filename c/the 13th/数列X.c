#include "stdio.h"
#include "math.h"
int main(void)
{
   int i, m, n;
   int repeat, ri;
   long f;
   long fib(int n);

   scanf("%d",&repeat);
   for(ri = 1; ri <= repeat; ri++){
        scanf("%d%d", &m, &n);
        for(i=1;fib(i)<m;i++);
        for(;fib(i)<=n;i++){
        	printf("%ld ", fib(i));
        	}
        printf("\n");
    }
}

long fib(int n){
	if(n==1||n==2)
		return 1;
	return fib(n-1)+fib(n-2);
	}
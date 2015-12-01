#include <stdio.h>
long fib(int n);
int main(void)
{
	int n,ri,repeat;

	scanf("%d",&repeat);
	for(ri=1;ri<=repeat;ri++){
		scanf("%d",&n);
		printf("fib(%d)=%ld\n",n,fib(n));
	}
}
long fib (int n){
	if(n==1)
		return 1;
	else if(n==0)
		return 0;
	else 	
	  return fib(n-1)+fib(n-2);	
	
	
	}

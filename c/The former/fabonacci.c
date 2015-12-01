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
long fib(int n){
	long result;
	if (n==0) 
		result=0;
	else if(n==1)
		result=1;
	else 
		result=fib(n-2)+fib(n-1);
	return result;
	}
	
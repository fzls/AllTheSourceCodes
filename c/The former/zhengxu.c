#include <stdio.h>
void func(long long int n){
	if(n/10)
		func(n/10);
	printf("%d ",n%10);
	}
int main(){
	long long int n,times;
	for(times=0;times<1000;times++){
	scanf("%d",&n);
		if(n<0)
		n=-n;
	func(n);
	printf("\n");
}
	}	
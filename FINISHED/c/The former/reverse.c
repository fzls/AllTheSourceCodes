#include <stdio.h>
void reverse(int n);
int main(void)
{
	int n,ri,repeat;

	scanf("%d",&repeat);
	for(ri=1;ri<=repeat;ri++){
		scanf("%d",&n);
		reverse(n);
		printf("\n");
	}
}
void reverse(int n){
	if(n<0)
		n=-n;
	if(n>0){
		printf("%d",n%10);
		reverse(n/10);
		}	
	
	}

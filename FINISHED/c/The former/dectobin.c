#include "stdio.h"
int main(void)
{
  int ri,repeat;
  int i,n;
  void dectobin(int n);

  scanf("%d",&repeat);
  for(ri=1;ri<=repeat;ri++){
    scanf("%d",&n);
    dectobin(n);
    if(n==0)
		printf("0");
    printf("\n");
  }
}
void dectobin(int n){
	if(n<0){
	printf("-");
	n=-n;
	}
	if(n>0)
		{
			dectobin(n/2);
			printf("%d",n%2);
			}
	
				
	}

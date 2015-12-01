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
    printf("\n");
  }
}

//二进制实现方法
  void dectobin(int n){
  	int s[16],i;
  	for(i=0;i<=15;i++){
  		s[i]=n%2;
  		n/=2;
  		}
  		for(i=15;i>=0;i--)
  		printf("%d",s[i]);
  	}
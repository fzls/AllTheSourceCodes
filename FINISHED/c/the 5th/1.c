#include <stdio.h>
#include <math.h>
int search(int n);
int main(void)
{
	int number,ri,repeat;

	scanf("%d",&repeat);
	for(ri=1;ri<=repeat;ri++){
		do{
			scanf("%d",&number);
		}while(number<101||number>999);
		printf("count=%d\n",search(number));
	}
}
int search(int n){
	  int a,b,c,count=0,i;
	  for(i=101;i<=n;i++){
    a=i%10;
		b=i/10%10;
		c=i/100;
		if((a==b&&b!=c||a==c&&a!=b||b==c&&a!=c)&&ceil(sqrt(i))==sqrt(i))
			count ++;
		}
		return count;
		
		}
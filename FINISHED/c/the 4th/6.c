
#include "stdio.h"
int main(void)
{
    int i, digit, m, n, number, sum;
    int repeat, ri;

    scanf("%d",&repeat);
    for(ri = 1; ri <= repeat; ri++){
        scanf("%d%d", &m, &n);
        printf("result:\n");
        for(i=m;i<=n;i++){
        	sum=0;
        	number=i;
        while(number!=0){
        	digit=number%10;
        	sum=sum+digit*digit*digit;
        	number=number/10;
        	}
        if(sum==i)
        	printf("%d\n", i);
        }
/*---------*/
    }
}
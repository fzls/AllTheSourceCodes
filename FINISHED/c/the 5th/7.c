
#include <stdio.h>
int main(void)
{
    int factor, m, n, number, sum,i;
    int repeat, ri;

    scanf("%d",&repeat);
    for(ri = 1; ri <= repeat; ri++){
        scanf("%d%d", &m, &n);
        printf("result:\n"); 	
        for(number=m;number<=n;number++){
        	sum=1;
        	for(i=2;i<number;i++)
        		if(number%i==0)
        			sum=sum+i;
        	if(sum==number){
        	printf("%d = 1", number);
        	for(i=2;i<=number;i++)
        		if(number%i==0){
        			factor=i;
        			printf(" + %d", factor);
        			}
           printf("\n");
        	}
        }
   
    }
}

#include <stdio.h>
int main(void)
{
    int j, m, n, number, sum,i;
    int repeat, ri;

    scanf("%d",&repeat);
    for(ri = 1; ri <= repeat; ri++){
        scanf("%d%d", &m, &n);
        printf("result:\n"); 
        for (i=m; i<=n; i++)
        {
        	sum=1;
        	for (j=2; j<=i/2; j++)
        	{
        		if (i%j==0) 
        		{
        			sum+=j;
        		}
        	}
        	if(i==sum)
        		{printf("%d = 1", i);
        			for (j=2; j<=i/2; j++)
        		if (i%j==0) 
					printf(" + %d", j);
					printf("\n");}
        }
    }
}
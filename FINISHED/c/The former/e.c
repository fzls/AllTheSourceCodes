#include "stdio.h"
int main(void)
{
    int i, j, n;
    int repeat, ri;
    double e, product;

    scanf("%d", &repeat);
    for(ri = 1; ri <= repeat; ri++){
        scanf("%d", &n);
        e=0;
        for (i=0; i<=n; i++)
        {
        	product=1;
        	for (j=1; j<=i; j++)
        	{
        		product=product*j;
        	}
        	e+=1/product;
        }
    	printf("e = %0.4f\n", e);
  }
}
#include <stdio.h>
int main(void)
{
    int repeat, ri;
    double x, y;  

    scanf("%d", &repeat);
    for(ri = 1; ri <= repeat; ri++){
        scanf("%lf", &x);
        if(x<0)
        	{
        		printf("enter a negative number\n");
        continue;}
        if(x!=0)
        	y=1.0/x;
        else 
        	y=0;	
        printf("f(%.2f) = %.1f\n", x, y);	
     }
}
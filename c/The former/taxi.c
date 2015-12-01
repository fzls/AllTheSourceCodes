#include <stdio.h>
int main(void)
{
    int repeat, ri;
    int minutes, seconds;
    double cost, mile;
	
    scanf("%d", &repeat);
    for(ri = 1; ri <= repeat; ri++){
        scanf("%lf%d%d", &mile, &minutes, &seconds);
        mile=mile+(minutes+1.0*seconds/60)/5;
        if(mile<=3)
        	cost=10;
        else if(mile<=10)
        	cost=10+2*(mile-3);
        else 
        	cost=24+3*(mile-10);
	printf("cost = %.0f\n", cost);
    }
}
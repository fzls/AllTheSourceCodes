#include <stdio.h>
int main(void)
{
    int repeat, ri;
    double rate, salary, tax;

    scanf("%d", &repeat);
    for(ri = 1; ri <= repeat; ri++){
        scanf("%lf", &salary);
        if(salary<=850)
        	tax=0;
        else if(salary<=1350)
        	tax=0.05*(salary-850)	;
        else if(salary<=2850)
           tax=0.1*(salary-850)	;
        else if(salary<=5850)
        	tax=0.15*(salary-850)	;
        else 
        	tax=0.2*(salary-850)	;
        printf("tax = %0.2f\n", tax);
    }
}
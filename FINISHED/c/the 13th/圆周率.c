#include <stdio.h>
double fact(int n){
	if(n==0||n==1)
		return 1;
	else 
		return n*fact(n-1);
	}
double multi(int n){
	if(n==1)
		return 1;
	else 
		return n*multi(n-2);	
	}
int main(void)
{	
    int i; 
    int repeat, ri;
    double eps, sum, item;

    scanf("%d", &repeat);
    for(ri = 1; ri <= repeat; ri++){
        scanf("%le", &eps);
        sum=0;i=0;
        do{
        	item=fact(i)/multi(2*i+1);
        	sum+=item;
        	i++;
        	}while(item>=eps);
        printf("PI = %0.5f\n", 2 * (sum+item));
    }

}

/*---------*/

/*---------*/
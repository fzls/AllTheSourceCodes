
	#include "stdio.h"
	double fact(int n);
	int main(void)
	{
	    int m, n;
	    int repeat, ri;
	    double s;
	
	    scanf("%d", &repeat);
	    for(ri = 1; ri <= repeat; ri++){
	        scanf("%d%d", &m, &n);
	        s=fact(n)/(fact(m)*fact(n-m));
	        printf("result = %.0f\n", s);
	    }
	}
	double fact(int n){
		int i;
		double product=1;
		for(i=1;i<=n;i++){
			product=product*i;
			}
		return product;	
		}
	 

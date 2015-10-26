#include <stdio.h>
#include <math.h>
int main(void)
{
    int i;
    int repeat, ri;
    double item, s, x; 
    double fact(int n);
    double fx(double x,int n);

    scanf("%d", &repeat);
    for(ri = 1; ri <= repeat; ri++){
        scanf("%lf", &x);
        int n; 
        item=n=1;
        s=0;
        while(item>=0.00001){
        	item=fx(x,n)/fact(n);
        	s+=item;
        	n++;
        	}
        
      	printf("s = %.2f\n", s);
    }
}
    double fact(int n){
    	double result=1;
    	int i;
    	for(i=1;i<=n;i++)
    	result*=i;
    	return result;
    	}
    double fx(double x,int n){
    	double result=1;
    	int i;
    	for(i=1;i<=n;i++)
    	result*=x;
    	return result;
    	}
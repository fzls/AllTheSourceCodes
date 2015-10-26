#include "stdio.h"
#include "math.h"
double funcos(double e, double x);
double fact(int n);
int main(void)
{
    int repeat, ri;
    double e, sum, x; 

    scanf("%d", &repeat);
    for(ri = 1; ri <= repeat; ri++){
        scanf("%le%le", &e, &x);
        sum=funcos(e,x);
        printf("sum = %f\n", sum);
    }
}
double funcos(double e, double x){
	double result=0,item;
	int i=0,flag=1;
	do{
		item=pow(x,i)/fact(i)*flag;
		result+=item;
		flag=-flag;
		i+=2;
		}while(fabs(item)>=e);
	return result;
	}
double fact(int n){
	int i;
	double result=1;
	for(i=1;i<=n;i++)
	result*=i;
	return result;
	}
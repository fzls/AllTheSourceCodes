#include "stdio.h"
#include "math.h"
double funcos(double e, double x);
double fact(int n){
   if(n==0||n==1)
   	return 1;
	else
	  return n*fact(n-1);
	}
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

double funcos(double e,double x){
	int flag=1;
	double result=0,item,i=0;
	item=flag*(pow(x, i))/fact(i);
	while(fabs(item)>=e/100){
		result+=item;
		flag=-flag;
		i+=2;
		item=flag*(pow(x, i))/fact(i);

		}
	return result+item;


	}

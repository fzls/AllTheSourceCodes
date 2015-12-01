#include <stdio.h>
#include <math.h>
float func(float x, int n){
	if(n==1)
		return x;
	else
		return pow(-1,n-1)*pow(x,n)+func(x,n-1);	
	}
int main(){
	float x;
	int n;
	scanf("%f%d",&x,&n);
	printf("the value of the func is %f\n",func(x,n));
	system("pause");
	
	
	}	
	
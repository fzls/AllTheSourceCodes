#include <stdio.h>
int main()
{
	int n,i,flag;
	double sum,item;
	scanf("%d",&n);
	sum=0;
	flag=1;
	for(i=1;i<=n;i++){
		item=flag*1.0/(2*i-1);
		sum=sum+item;
		flag=-flag;
		}
	printf("the sum is %lf\n",sum);
	system("pause");
	return 0;	
	
	}
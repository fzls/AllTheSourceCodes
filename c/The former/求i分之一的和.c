#include <stdio.h>
int main()
{
	int n,i,j,repeat;
	printf("input repeat\n");
	scanf("%d",&repeat);
	for(j=1;j<=repeat;j++){
	double sum=0;
	printf("input a positive integar n\n");
	scanf("%d",&n);
	for (i=1; i<=n; i++)
	{
		sum=sum+1.0/i;
	}
   printf("the sum =%lf\n",sum);
}
	system("pause");
	return 0;
	}
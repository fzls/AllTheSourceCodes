#include <stdio.h>
int main()
{
	int i,repeat,j,n;
   double sum,item;
   printf("input repeat\n");
   scanf("%d",&repeat);
   for (i=1; i<=repeat; i++)
   {
   	printf("input n=");
		scanf("%d",&n);
		sum=0;
		for(j=1; j<=n; j++)
		{
			item=1.0/(2*j-1);
			sum=sum+item;
		}
		printf("the sum is ",sum);
	system("pause");
   }
}
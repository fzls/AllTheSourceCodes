#include <stdio.h>
int main()
{
	int n,i,fact=1;
	printf("input n\n");
	scanf("%d",&n);
	for (i=1; i<n; i++)
	{
		fact=fact*i;
	}
	printf("the fact =%d\n",fact);
	system("pause");
	return 0;
	}
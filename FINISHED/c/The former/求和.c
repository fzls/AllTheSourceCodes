#include <stdio.h>
int main()
{
	int i,n,sum=0;
	printf("input a positive integar n\n");
//	for the concern of pleasing to the eye,put the \n in the end of the sentence
	scanf("%d",&n);
//	pay attention to the "&"
	for(i=1;i<=n;i++){
		sum=sum+i;
		}
		printf("the sum is %d\n",sum);
		system("pause");
		return 0;
	}
	
	
	
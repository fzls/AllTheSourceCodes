#include <stdio.h>
#include <math.h>
int main(void){
     int m,n,count,sum,i,j,k,repeate;
     printf("input the repeate times\n",repeate);
     scanf("%d",&repeate);
     for(k=1;k<=repeate;k++){
     printf("input a m and n\n");
     scanf("%d%d",&m,&n);
     sum=0;
     	count=0;
     for(i=m;i<=n;i++)
     {
     	
     	for(j=2;j<i;j++){
     		if(i%j==0)
     			break;
     		}
     		if(j==i)
     			{count++;
     				sum+=i;}
     	}
     	printf("the count is %d and the sum is %d\n",count,sum);
    }
     system("pause");
     return 0;
}
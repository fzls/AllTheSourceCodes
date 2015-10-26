#include <stdio.h>
#include <math.h>
int main(){
   int m, n , i, j;
   scanf("%d%d",&m,&n);
   for(i=m;i<=n;i++)
      for(j=i-1;j>=m;j--)
           if((int)sqrt(i+j)*(int)sqrt(i+j)==(i+j)&&(int)sqrt(i-j)*(int)sqrt(i-j)==(i-j))
           	printf("(%d,%d)\n",i,j);
   system("pause");
           	
}
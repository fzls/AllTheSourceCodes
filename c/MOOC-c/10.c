#include <stdio.h>
int main(){
   int i, j ,k, a,count=0;
   scanf("%d",&a);
   for(i=a;i<a+4;i++)
   for(j=a;j<a+4;j++)
   for(k=a;k<a+4;k++)
   if(i!=j&&j!=k&&k!=i){
   	printf("%d%d%d",i,j,k);
   	if(++count%6)
   		printf(" ");
   	if(count%6==0)
   		printf("\n");

  }
}

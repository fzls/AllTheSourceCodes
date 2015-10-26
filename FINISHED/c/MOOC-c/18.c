#include <stdio.h>
int main(){
   int a, n, i, j;
   int s=0, temp;
   scanf("%d%d",&a,&n);

   for(i=1;i<=n;i++){
   	temp=0;
   	for(j=0;j<i;j++)
   	 temp=10*temp+a;
   	s+=temp;

   	}
   printf("%d\n",s);

}

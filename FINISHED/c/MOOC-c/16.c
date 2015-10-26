#include <stdio.h>
int main(){
   int m, n, i;
   scanf("%d/%d",&m,&n);
   for(i=2;i<=m;i++)
      while(m%i==0&&n%i==0){
      	m/=i;
      	n/=i;
      	}
   printf("%d/%d\n",m,n);
      	
}
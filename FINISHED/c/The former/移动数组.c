#include <stdio.h>
void mov(int *,int n, int m);
int main(){
   int n,m,*a,i;
   scanf("%d%d",&n,&m);
   
   a=(int *)malloc((n+m)*sizeof(int));
   for(i=0;i<n;i++)
      scanf("%d",a+i);
   mov(a,n,m);
   system("pause");
      
}
void mov(int *a, int n, int m){
	int i;
	for(i=n-1;i>=0;i--)
	a[i+m]=a[i];
	for(i=0;i<m;i++)
	a[i]=a[n+i];
	for(i=0;i<n;i++)
	printf("%d",a[i]);
	printf(" \n");
	
	
	
	}
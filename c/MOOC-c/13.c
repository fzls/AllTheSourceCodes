#include <stdio.h>
int prime(int n){
	int i;
	for(i=2;i<n;i++)
	 if(n%i==0)
	 	return 0;
	return 1;
	}
int main(){
   int m, n, i, s=0, count=0;
   scanf("%d%d",&m,&n);
   if(m==1)
   	++m;
   for(i=m;i<=n;i++)
     if(prime(i)){
     	++count;
     	s+=i;
     	}
  printf("%d %d\n",count,s);


}

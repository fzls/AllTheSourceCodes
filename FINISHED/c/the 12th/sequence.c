#include <stdio.h>
int main(){
   int i,j,n,x;
   int a[10];
   int repeat,ri;
   
   scanf("%d",&repeat);
   for(ri=0;ri<repeat;ri++){
   	scanf("%d",&n);
   	for(i=0;i<n;i++)
   	   scanf("%d",&a[i]);
   	scanf("%d",&x);
   	for(i=0;i<n;i++)
   	if(x<a[i])
   	  break;
   	for(j=n-1;j>=i;j--)
        a[j+1]=a[j];
      a[i]=x;
        for(i = 0; i < n + 1; i++)
            printf("%d ", a[i]);
        putchar('\n');        
   	
   	
   	
   	}
}
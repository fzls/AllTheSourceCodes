#include <stdio.h>
int main(void)   
{
    int i, j, n, x;
    int repeat, ri;
    int a[10];

    scanf("%d", &repeat);
    for(ri = 1; ri <= repeat; ri++){
        scanf("%d", &n);
        for(i = 0; i < n; i++)
            scanf("%d", &a[i]);
        scanf("%d", &x);
        	if(x<a[0]){
        		for(j=n;j>=1;j--)
        		    a[j]=a[j-1];
        		a[0]=x;    
        	}
        	else if(x>a[n-1])
        		a[n]=x;
        	else
        		 for(j=0;j<n;j++)
        		   if(x>=a[j]&&x<=a[j+1]){
        		   	for(i=n;i>=j+2;i--)
        		   	  a[i]=a[i-1];
        		   	a[j+1]=x; 
        		   	break;
        			}
        for(i = 0; i < n + 1; i++)
            printf("%d ", a[i]);
        putchar('\n');   
    }
}
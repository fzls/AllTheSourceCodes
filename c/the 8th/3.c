#include <stdio.h>
int main(void)
{
    int i, index, j, n, t;
    int repeat, ri;
    int a[10];

    scanf("%d", &repeat);
    for(ri = 1; ri <= repeat; ri++){
        scanf("%d", &n);
        for(i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for(i=0;i<n;i++){
        	index=i;
        	for(j=i;j<n;j++)
        	   if(a[j]>a[index])
        	   	index=j;
        	t=a[i];
        	a[i]=a[index];
        	a[index]=t;
        	}    
            
        printf("After sorted: ");
        for(i = 0; i < n; i++) 
            printf("%d ", a[i]);
        printf("\n");
    }
}
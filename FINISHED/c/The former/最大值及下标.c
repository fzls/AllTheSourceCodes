#include <stdio.h>
int main( )
{
    int i, index, n, temp;
    int repeat, ri;
    int a[10];

    scanf("%d", &repeat);
    for(ri = 1; ri <= repeat; ri++){
        scanf("%d", &n);
        index=n-1;
        for(i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for(i=n-2;i>=0;i--)
           if(a[i+1]<a[i])
           	index=i;
        printf("max = %d, index = %d\n",a[index],index);
        temp=a[n-1];a[n-1]=a[index];a[index]=temp;   	    
        for(i = 0; i < n; i++) 
            printf("%d ", a[i]);
        printf("\n");
    }
}
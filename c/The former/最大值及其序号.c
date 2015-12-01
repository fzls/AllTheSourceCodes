#include <stdio.h>
int main(void)
{
    int i, index, n;
    int ri, repeat;
    int a[10];

    scanf("%d", &repeat);
    for(ri = 1; ri <= repeat; ri++){
    	 index=0;
        scanf("%d", &n);
        for(i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for(i=0;i<n;i++){
        	if(a[index]<a[i])
        			index=i;
        	}    
        printf("max = %d, index = %d\n", a[index], index);
    }
}
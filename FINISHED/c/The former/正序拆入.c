#include <stdio.h>
int main(void)   
{
    int i, j, n, x,t;
    int repeat, ri;
    int a[10];

    scanf("%d", &repeat);
    for(ri = 1; ri <= repeat; ri++){
        scanf("%d", &n);
        for(i = 0; i < n; i++)
            scanf("%d", &a[i]);
        scanf("%d", &x);
        if(x<a[0]){
           t=a[0];
           a[0]=x;
           for(i=n-1;i>=1;i--)
           a[i+1]=a[i];
           a[1]=t;
           goto over;}
        else if(x>a[n-1]){
        a[n]=x;
      goto over;}
        for(i=0;i<n-1;i++)
        if(a[i]<=x&&a[i+1]>=x){
        t=a[i+1];
        a[i+1]=x;
        for(j=n-1;j>=i+2;j--)
        a[j+1]=a[j];
        a[i+2]=t;
        goto over;
        }
        over:;
        for(i = 0; i < n + 1; i++)
            printf("%d ", a[i]);
        putchar('\n');   
    }
}

#include "stdio.h"
int main(void)
{
    int flag, i, j, k, row, col, n;
    int a[6][6];
    int repeat, ri;

    scanf("%d", &repeat);
    for(ri = 1; ri <= repeat; ri++){
        scanf("%d", &n);
        flag=0;
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                scanf("%d", &a[i][j]);
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++){
            for(k=0;k<n;k++){
            if(a[i][k]>a[i][j])
            	  goto again;
            if(a[k][j]<a[i][j])
            	goto again ;}
            flag=1;
            row=i;
            col=j;
            goto end;
            again:;
          }
          end:;
        if(flag != 0)
            printf("a[%d][%d] = %d\n", row, col,a[row][col]);
        else
            printf("NO\n");
    }
}
#include <stdio.h>
int main(void)
{
    int i, j, k=0, (*p)[3],a[3][3];
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
        a[i][j]=k++;
    p=a;
    printf("%d\n",(*p++)[2]);
    printf("%d\n",(*p++)[1]);
    printf("%d\n",(*p)[0]);
    printf("%d\n",*((*p--)+1));
    printf("%d\n",*((*p--)+1));
}

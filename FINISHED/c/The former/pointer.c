#include <stdio.h>
int main(void)
{
    int x, y;
    int *p;
    x = 100;
    p = &x;
    y = *p;
    printf("%d", y); /* this will be wrong */
    return 0;
}
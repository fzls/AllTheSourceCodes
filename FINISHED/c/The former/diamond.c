#include "stdio.h"
double fi(int n) {
    if (n == 1 || n == 2)
        return 1;
    else
        return fi(n - 1) + fi(n - 2);
}
int main(void)
{
    int i, j, n;
    int repeat, ri;

    scanf("%d", &repeat);
    for (ri = 1; ri <= repeat; ri++) {
        scanf("%d", &n);
        for (i = 1; i <= n; i++) {
            for (j = n - i; j >= 0; j--)
                printf("  ");
            for (j = 1; j <= 2 * i - 1; j++)
                printf("%lf ", fi(i + j - 1));
            printf("\n");
        }

        for (i = n - 1; i >= 1; i--) {
            for (j = 0; j <= n - i; j++)
                printf("  ");
            for (j = 2 * i - 1; j >= 1; j--)
                printf("* ");
            printf("\n");
        }
        printf("\n");
    }
}

#include <stdio.h>
#include <string.h>
void PDN(int *a, int k, int n) {
   int i;
   printf("%d ", a[k]);
   for (i = k; i < n; i++)
      *(a + i) = *(a + i + 1);

}
int output( int *a, int m, int k, int n) {
   if (n == 1) {
      printf("%d \n", a[0]);
      return 0;
   }
   k = (k + m - 1) % n;
   PDN(a, k, n);
   output(a, m, k, --n);
}

int main() {
   int ri, times, m, n, k, i;
   int  *a;
   scanf("%d", times);
   for (ri = 0; ri < times; ri++) {
      a = NULL;
      scanf("%d", &n);
      if ((a = (int *)malloc(n * sizeof(int) + 1)) == NULL)
      {
         printf("Not able to allocate memory\n");
         exit(1);
      };
      for (i = 0; i < n; i++)
         *(a + i) = i + 1;
      *(a + n) = '\0';
      scanf("%d", &m);
      k = 0;
      output(a, m, k, n);
      free(a);
      system("pause");

   }
}

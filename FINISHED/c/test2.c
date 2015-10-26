#include <stdio.h>
#include <string.h>
int main() {
   int n, i, flag, j, flag2, nal, nac, nar;
   char s[100], PT[100];
   scanf("%d", &n);
   fflush(stdin);
   for (i = 0; i < n; i++) {
      scanf("%s", s);

      flag = 0;
      j = 0;
      while (s[j] != 0) {
         if (s[j] != 'P' && s[j] != 'A' && s[j] != 'T') {
            printf("NO\n");
            flag = 1;
            break;
         }
         ++ j;
      }
      if (flag)
         continue;



      flag2 = 0; nal = nac = nar = 0;
      for (j = 0; s[j] != 'P'; j++)
         nal++;
      for (j = j + 1; s[j] != 'T'; j++)
         nac++;
      for (j = j + 1; s[j] != 0; j++)
         nar++;


      if (nal == 0 && nar == 0 && nac >= 1)
         flag2 = 1;
      else if (nal != 0 && nac == nar / nal)
         flag2 = 1;
      else
         flag2 = 0;
      if (flag2)
         printf("YES\n");
      else
         printf("NO\n");

   }
}

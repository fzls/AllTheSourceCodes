#include <stdio.h>
int main(){
   int foot, inch, cm;
   scanf("%d",&cm);
   foot = (int)(cm/(100*0.3048));
   inch = (int)((cm/(100*0.3048)-foot)*12);
   printf("%d %d\n",foot,inch);
   system("pause");
   
}
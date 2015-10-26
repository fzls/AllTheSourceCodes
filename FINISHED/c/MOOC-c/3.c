#include <stdio.h>
int main(){
   int a, b, c;
   scanf("%d %d",&a,&b);
   c = a / 100 *60 +a % 100 + b;
   printf("%d%02d\n",c/60,c%60);
   system("pause");
   
   
}
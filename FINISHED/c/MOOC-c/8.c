#include <stdio.h>
int main(){
   int a, b, c;
   scanf("%d:%d",&a,&b);
   if(a<12)
   	printf("%d:%d AM\n",a,b);
   else if(a==12)
   	printf("%d:%d PM\n",a,b);
   else	
     printf("%d:%d PM\n",a-12,b);
   system("pause");
   	
}
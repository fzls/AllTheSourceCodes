#include <stdio.h>
int main(){
   int a , s=0;
   scanf("%d",&a);
   while(a!=0){
   	s=10*s+a%10;
   	a/=10;
   	}
   printf("%d\n",s);
   system("pause");
   	
}
#include <stdio.h>
int main(){
	int a=100,ri,c,d;
	int *p=&a;
   printf("%d %o %x\n",10,10,10);
   printf("%p %d\n",p,*p);
   for(ri=0;ri<100;ri++){
   scanf("%d%*c%d",&c,&d);
   printf("%d %d\n",c,d);
 }
   
   
   system("pause");
   
}
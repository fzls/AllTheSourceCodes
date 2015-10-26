#include <stdio.h>
#define MAX 20
int main(){
   int n, x, s[MAX], i, flag = 0;
   scanf("%d%d",&n,&x);
   for(i = 0; i < n; i++)
   scanf("%d",&s[i]);

   for(i = 0; i < n; i++)
   if(s[i] == x){
   	printf("%d\n",i);
   	flag = 1;
   	break;
   	}
   if(!flag)
   	printf("Not Found\n");

}

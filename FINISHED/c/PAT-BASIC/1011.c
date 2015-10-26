#include <stdio.h>
int main(){
   long long  a, b, c;
   int n, i = 1;
   scanf("%d",&n);
   
   while(n--){
   scanf("%lld%lld%lld",&a, &b, &c);
   if(a + b > c)
   	printf("Case #%d: true\n",i++);
   else
   	printf("Case #%d: false\n",i++);	
   
 }
}
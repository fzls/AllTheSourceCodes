#include <stdio.h>
char *ToF(int n){
	if(n == 1)
		return "true";
	else if(n == 0)
		return "false";	
	}
int main(){
   long int a, b, c, n, i;
   scanf("%ld",&n);
   for(i = 1; i <= n; i++){
   	scanf("%ld%ld%ld",&a,&b,&c);
   	printf("Case #%d: %s\n",i,ToF( a + b > c ));
   	}
   system("pause");
      
}
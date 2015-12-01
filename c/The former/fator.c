#include <stdio.h>
#include <math.h>
void exits( char c){
	if(c=='y')
		exit(1);
	}
int facto(int n){
	int i,count=0;
	for(i=101;i<=n;i++){
		if(ceil(sqrt(i))!=sqrt(i))
			continue;
		int a,b,c;
		a=i%10;
		b=i/10%10;
		c=i/100;
	if(a==b&&a==c||a!=b&&b!=c&&c!=a)
		continue;
	count++;		
  }
  return count;	
	}
int main(){
   int n,ri;
   char c;
   for(ri=1;ri<=1000;ri++){
   	printf("please enter an integer \n");
   	scanf("%d",&n);
   	printf("the number of the number you want is %d\n",facto(n));
   	printf("do you want to exit? y for yes and n for no\n");
   	scanf("%c",&c);
   	exits(c);
   	}
}
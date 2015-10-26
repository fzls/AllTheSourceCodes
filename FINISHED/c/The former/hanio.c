#include <stdio.h>
int i=0;
void hanio(int n, char a, char b, char c);
int main(){
   int n,ri;
   for(ri=0;ri<1000;ri++){
   printf("input the numbers of the disks\n");
   scanf("%d",&n);
   printf("the steps for %d disks are:\n\n",n);
   hanio(n,'a','b','c');
  } 
}
void hanio( int n, char a, char b, char c){
	if(n==1)
		printf("%c-->%c     %d\n",a,b,i++);
	else{
	   hanio(n-1,a,c,b);
	   printf("%c-->%c     %d\n",a,b,i++);
	   hanio(n-1,c,b,a);
	 }
	
	
	}
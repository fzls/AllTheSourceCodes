#include <stdio.h>
int main(){
   char ch;
   while( (ch=getchar()) != '#' ){
   	if(ch >= 'A' && ch <= 'Z')
   		printf("%c",'a' + ch - 'A');
   	else if(ch >= 'a' && ch <= 'z')
   		printf("%c",'A' + ch - 'a');
   	else
   	  printf("%c",ch);
   	}
   system("pause");
   
}
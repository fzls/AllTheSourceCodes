#include <stdio.h>
void delchar(char *s, char c);
int main(){
   char s[100],c;
   gets(s);
   c=getchar();
   delchar(s,c);
}
void delchar(char *s, char c){
	int i,j;
	char t[100];
	for(i=0,j=0;s[i]!=0;i++)
	if(s[i]!=c)
		t[j++]=s[i];
	t[j]=0;
	puts(t);

	}

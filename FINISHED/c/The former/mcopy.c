#include <stdio.h>
void mcopy(char *s,char *t,int m);
int main(){
   char s[100],t[100];
   int m;
   gets(s);
   scanf("%d",&m);
   mcopy(s, t, m);
   system("pause");
   
}
void mcopy(char *s, char *t, int m){
	int i,j;
	for(i=m-1,j=0;s[i]!='\0';i++,j++)
	t[j]=s[i];
	t[j]='\0';
	puts(t);
		
	}

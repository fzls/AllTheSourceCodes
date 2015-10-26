#include <stdio.h>
int main(void){
	  int a,b,str[1000],i=0,j;
	  char ch;
	  
	  while((ch=getchar())!='\n'){
     scanf("%d",&b);
     a=ch-'0';
   printf("%d ",a+b);
   str[i]=a;str[i+1]=b;
   i+=2;
}
   printf("\n");
    for(j=0;j<i;j++)
    printf("%d ",str[j]);
    system("pause");
}
   
     
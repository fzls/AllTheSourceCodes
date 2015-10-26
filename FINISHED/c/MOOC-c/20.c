#include <stdio.h>
int main(){
   float nleft, nright;
   char op;
   scanf("%d",&nleft);
   while((op=getchar()) != '='){
   	scanf("%d",&nright);
   	switch(op){
   	   case '+': nleft+=nright;break;
   	   case '-': nleft-=nright;break;
   	   case '*': nleft*=nright;break;
   	   case '/': if(nright==0) {printf("ERROR");exit(0);}
   	               else  nleft/=nright;break;
   	   default:printf("ERROR");exit(0);break;
   	}
   	}
   printf("%f\n",nleft);

}

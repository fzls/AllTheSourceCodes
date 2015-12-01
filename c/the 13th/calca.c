#include <stdio.h>
int main(void)
{
    char operator;
    int operand1, operand2, res;
    int repeat, ri;

    scanf("%d", &repeat);
    for(ri = 1; ri <= repeat; ri++){
        scanf("%d", &operand1);
        res=0;
        while((operator = getchar())!='='){
        	scanf("%d", &operand2);
        	switch(operator){
        	   case '+': operand1+=operand2;break;
        	   case '-': operand1-=operand2;break;
        	   case '*': operand1*=operand2;break;
        	   case '/': operand1/=operand2;break;
        	}
        	}
        res=operand1;
        printf("%d\n", res);
   }
}

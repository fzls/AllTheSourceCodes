#include "stdio.h"
int main(void)
{
    int i, m, n;
    int repeat, ri;
    int is(int number); 
  
    scanf("%d", &repeat);
    for(ri = 1; ri <= repeat; ri++){
        scanf("%d%d", &m, &n);
        printf("result:\n");
        for(i=m;i<=n;i++){
        	if(is(i)==1)
        		printf("%d\n", i);
        	}
    }
}
    int is(int number){
    	int digit,sum=0,temp,result=0;
    	temp=number;
    	do{
    		digit=temp%10;
    		sum+=digit*digit*digit;
    		temp/=10;
    		}while(temp!=0);
    	if(sum==number)	
    		result=1;
    	return result;
    	}
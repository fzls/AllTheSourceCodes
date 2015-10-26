#include "stdio.h"
int main(void)
{
    int count, digit, in; 
    int repeat, ri;
    int countdigit(int number, int digit);

    scanf("%d",&repeat);
    for(ri = 1; ri <= repeat; ri++){
        scanf("%d%d", &in, &digit);
        count=countdigit(in,digit);
        printf("Number %d of digit %d: %d\n", in, digit, count);
    }
}
int countdigit(int number, int digit){
	int x,count=0;
	do{
		x=number%10;
		number/=10;
		if(x==digit)
			count++;
		}while(number!=0);
	return count;
	}

#include <stdio.h>
int main(void)
{
    int count, in, sum;
    int repeat, ri;
    
    scanf("%d", &repeat);
    for(ri = 1; ri <= repeat; ri++){
        scanf("%d", &in);
        sum=0;
        count=0;
        do{
        	sum=sum+in%10;
        	in=in/10;
        count ++;}while(in!=0);
      	if(sum<0)
      	sum=-sum;
 	     printf("count = %d, sum = %d\n", count, sum);
   }
}
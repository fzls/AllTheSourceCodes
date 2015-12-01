#include <stdio.h>
int main(void)
{
    int x, sum;
    int repeat, ri;


    scanf("%d", &repeat);
    for(ri = 1; ri <= repeat; ri++){
        scanf("%d", &x);
        sum=0;
        while (x>0) {
        	if(x%2==1)
        	sum+=x; 
        	scanf("%d",&x);
        }
      	printf("The sum of the odd numbers is %d.\n", sum);
   }
}
 
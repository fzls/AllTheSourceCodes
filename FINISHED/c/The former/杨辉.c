#include "stdio.h"
long int fact(int n){
	if(n==0||n==1)
		return 1;
	else	
		return n*fact(n-1);
	}
int main(void)
{
    int i, j, n;
    int repeat, ri; 
	
    scanf("%d", &repeat);
    for(ri = 1; ri <= repeat; ri++){
        scanf("%d", &n);
        int count = 1;
        for(i=1;i<=n;i++){
        	for(j=n-i;j>=0;j--)
        	printf("  ");
        	for(j=0;j<=i-1;j++)
           printf("%ld   ",fact(i-1)/(fact(j)*fact(i-1-j)));
        printf("\n");
        }

        	}
    }

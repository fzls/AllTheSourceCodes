#include "stdio.h"
#define MAXLEN 80
int main(void)
{ 
    char cc, ch;
    char str[MAXLEN];
    int  flag, i,j, index;
    int repeat, ri;
	
    scanf("%d", &repeat);
    getchar();
    for(ri = 1; ri <= repeat; ri++){
        cc = getchar();
        flag=0;
        getchar();

        i = 0;
        while((ch = getchar()) != '\n'){
            str[i++] = ch;
        }
        for(j=i-1;j>=0;j--){
        	if(str[j]==cc)
        		{
        			flag=1;
        			index=j;
        			goto end;
        			}
        	}
        end:;
        if(flag != 0)  
            printf("index = %d\n", index);
        else 
            printf("Not Found\n");
    }
}
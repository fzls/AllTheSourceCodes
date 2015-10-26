#include "stdio.h"
#define MAXLEN 80
int main(void)
{
    char ch;
    char str[MAXLEN];
    int count, i;
    int repeat, ri;

    scanf("%d", &repeat);
    getchar();
    for(ri = 1; ri <= repeat; ri++){
        i = count = 0;
        while((ch = getchar()) != '\n'){
            str[i++]=ch;
        }
        str[i] = 0;
        for(i=0;str[i]!=0;i++){
        	if(str[i]>='A'&&str[i]<='Z')
        		switch(str[i]){
        			case'A':case'E':case'I':case'O':case'U':;break;
        			default:
        				count++;
        			
        			}
        	}
        printf("count = %d\n", count);
    }
}
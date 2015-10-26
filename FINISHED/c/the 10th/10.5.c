#include "stdio.h"
#include "string.h"
#define MAXLEN 80
int main(void)
{  
    char ch;
    char str[MAXLEN], num[MAXLEN];
    int i, k;
    int repeat, ri;
    long number;

    scanf("%d", &repeat);
    getchar();
    for(ri = 1; ri <= repeat; ri++){
        i = 0;
        while((ch = getchar()) != '\n'){
            str[i]=ch;
            i++;
        }
        str[i] = 0;
        k=0;
        for(i=0;str[i]!=0;i++)
            if(str[i]>='a'&&str[i]<='f'||str[i]>='A'&&str[i]<='F'||str[i]>='0'&&str[i]<='9')
            	num[k++]=str[i];
        num[k]=0;    	
        number=0;
        for(k=0;num[k]!=0;k++)
            if(num[k]>='0'&&num[k]<='9')
            	   number=16*number+num[k]-'0';
            else if(num[k]>='a'&&num[k]<='f')
            	   number=16*number+num[k]-'a'+10;
            else if(num[k]>='A'&&num[k]<='F')
            	   number=16*number+num[k]-'A'+10;	   	   
        
      	printf("Dec = %ld\n",number);
    }
}
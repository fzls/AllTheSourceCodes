#include <stdio.h>
int main(void)
{
    char c;
    int count, word;
    int repeat, ri;

    scanf("%d", &repeat);
    getchar();
    for(ri = 1; ri <= repeat; ri++){
        count=0;
        word=0;
        while ((c = getchar())!='\n') {
        	 if(c>='a'&&c<='z'||c>='A'&&c<='Z'||c=='\''||c>='0'&&c<='9'){
        	 	if(word==0)
        	 		count++;
        	word=1;
        	}
        	 if(c==' ')
        	 	word=0;	
        }
        printf("count = %d\n", count);
    }
}

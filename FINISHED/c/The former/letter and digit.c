#include <stdio.h>
int main(void)
{
    char c;
    int blank, digit, letter, other;
    int ri, repeat;

    scanf("%d", &repeat);
    for(ri = 1; ri<=repeat; ri++){
    	letter=blank=digit=other=0;
    	while((c=getchar())!='\n'){
    		if(c>='a'&&c<='z'||c>='A'&&c<='Z')
    			letter++;
    		else if(c>='0'&&c<='9')
    			digit++;
    		else if(c!=' ')
    			other++;	
    		else
    			blank++;	
    		}
        
        printf("letter = %d, blank = %d, digit = %d, other = %d\n", letter, blank, digit, other);
    }
}

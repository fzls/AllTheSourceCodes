#include <stdio.h> 
int main(void)
{
    int i, j;
    char str[80];		

    i = 0;
    while((str[i] = getchar( )) != '\n') 
        i++; 
    for(j = i-1; j>=0; j--) 
        putchar(str[j]);
    printf("\n");    
    system("pause");    
}
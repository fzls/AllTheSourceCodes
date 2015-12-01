#include<stdio.h>
void main()
{
    char c;
    char str[80];
    int repeat, ri;
    void delchar(char *str, char c);

    scanf("%d", &repeat);
    getchar();
    for(ri = 1; ri <= repeat; ri++){
        gets(str);
        scanf("%c", &c);
        getchar();
        delchar(str,c);
        printf("result: ");
        puts(str);
    }
}

void delchar(char *str, char c){
	int i,j,k,m;
	for(i=0;*(str+i)!='\0';i++);
	k=i;
	for(j=0;*(str+j)!='\0';j++)
	    if(*(str+j)==c){
	    	   for(i=j;i<k-1;i++)
	    	     *(str+i)=*(str+i+1);
	    	   *(str+i)='\0';  
	    	   k--;
	    	   j--;
	}
		}
	

#include <stdio.h>
void main()
{
    char s[80];
    int repeat, ri;
    int mirror(char *p);
 
    scanf("%d", &repeat);
    getchar();
    for(ri = 1; ri <= repeat; ri++){
        gets(s);
        if(mirror(s) != 0)
      	    printf("YES\n");
        else
            printf("NO\n");
    }
}

int mirror(char *p){
	int i,j,flag=1,n=0;
	while(*(p+n)!='\0')n++;
	for(i=0,j=n-1;i<j;i++,j--){
		if(*(p+i)!=*(p+j)){
		flag=0;
		break;
		}
		}
	return flag;
	
	}

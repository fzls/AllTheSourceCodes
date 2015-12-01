#include <stdio.h>
void mov(int *x, int n, int m);
int main(void)
{
    int i, m, n;
    int a[80];

    scanf("%d%d", &n, &m);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    mov(a,n,m);    
    printf("After move: ");
    for(i = 0; i < n; i++)
         printf("%d ", a[i]);
    printf("\n"); 
    system("pause");
    
}

void mov(int *x, int n, int m){
	int i;
	for(i=n-1;i>=0;i--)
	   *(x+i+m%n)=*(x+i);
	for(i=0;i<m%n;i++)
	   *(x+i)=*(x+n+i);   
	
	
	}
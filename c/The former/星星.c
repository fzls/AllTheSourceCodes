#include <stdio.h>
int main(void){
	int i,j;
	for(i=1;i<=4;i++){
		for(j=1;j<i;j++)
		printf(" ");
		for(j=5-i;j>=1;j--)
		printf("* ");
		printf("\n");
		}
     system("pause");
     return 0;
}
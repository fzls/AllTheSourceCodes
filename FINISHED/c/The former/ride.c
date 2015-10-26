/*
ID: fzls0421
LANG: C
TASK: ride
*/
#include <stdio.h>
main () {
	char str1[6],str2[6];
	int i,product1=1,product2=1;
	for(i=0;(str1[i]=getchar())!='\n';i++)
	for(i=0;(str2[i]=getchar())!='\n';i++)
	for(i=0;str1[i]!='\n';i++)
	product1*=(str1[i]-'A'+1);
	for(i=0;str2[i]!='\n';i++)
	product2*=(str2[i]-'A'+1);
    if((product1%47)==(product2%47))
    	printf("GO\n");
    else 
    	printf("STAY\n");	
    	system("pause");
}
#include <stdio.h>
int main(){
	char ch,A,B,C,D,E;
	printf("input a lettter of A~E\n");
	scanf("%c",&ch);
	switch (ch)
	{
		case 'A':printf("90~100\n");break;
		case 'B':printf("80~89\n");break;
		case 'C':printf("70~79\n");break;
		case 'D':printf("60~69\n");break;
		case	'E':printf("0~59\n");break;	
		default:
			
	}
	system("pause");
	return 0;
	}

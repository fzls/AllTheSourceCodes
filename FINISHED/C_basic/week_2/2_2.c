/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 (1054073896@qq.com)
* @FILE NAME :2_2.c
* @version : 1.0
* @Time: 2015-07-18 11:19:15
* @Description:报头编码
*
+----------------------------------------------------------
*/
#include "stdio.h"
#include "stdlib.h"

int main() {
	int RS, R, S;
	scanf("%d", &RS);
	while (RS < 11 || RS > 59)
	{
		printf("there is something wrong with your input,please input again\n");
		scanf("%d", &RS);
	}
	R = RS / 10;
	S = RS % 10;
	switch (R) {
	case 1: printf("Unreadable, "); break;
	case 2: printf("Barely readable, occasional words distinguishable, "); break;
	case 3: printf("Readable with considerable difficulty, "); break;
	case 4: printf("Readable with practically no difficulty, "); break;
	case 5: printf("Perfectly readable, "); break;

	}
	switch (S) {
	case 1: printf("Faint signals, barely perceptible.\n"); break;
	case 2: printf("Very weak signals.\n"); break;
	case 3: printf("Weak signals.\n"); break;
	case 4: printf("Fair signals.\n"); break;
	case 5: printf("Fairly good signals.\n"); break;
	case 6: printf("Good signals.\n"); break;
	case 7: printf("Moderately strong signals.\n"); break;
	case 8: printf("Strong signals.\n"); break;
	case 9: printf("Strong signals.\n"); break;

	}
	system("pause");
	return 0;
}


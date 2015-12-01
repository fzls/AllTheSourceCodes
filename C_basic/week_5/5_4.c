/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME :5_4.c
* @version： v1.0
* @Time: 2015-07-19 21:17:11
* @Description: 构建素数表
*
+----------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#define	MAXNUM 100
int main() {
	int isprime[MAXNUM];
	// 初始化素数表
	for (int i = 0; i < MAXNUM; i++) {
		isprime[i] = 1;
	}
	// 构建素数表
	for (int i = 2; i < MAXNUM; i++) {
		if (isprime[i]) {
			for (int j = 2; i * j < MAXNUM; j++) {
				isprime[i * j] = 0;
			}
		}
	}
	// 打印素数表,每五个换行
	for (int i = 2, count = 0; i < MAXNUM; i++) {
		if (isprime[i]) {
			printf("%d\t", i);
			if (++count % 5 == 0) {
				printf("\n");
			}
		}
	}
	printf("\n");

	system("pause");
	return 0;
}


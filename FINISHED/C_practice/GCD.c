/*
+----------------------------------------------------------
*
* @authors: ��֮���� <1054073896@qq.com>
* @FILE NAME:	 TM_FILENAME
* @version:	 v1.0
* @Time: 		 2015-07-21 21:45:15
* @Description: ŷ�������������㷨ʵ��
*
+----------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
int gcd(int x, int y);
int main() {
	int x, y;
	printf("������x��y\n");
	scanf("%d%d", &x, &y);
	printf("%d��%d�����������%d\n", x, y, gcd(x, y));

	printf("\n");
	system("pause");
	return 0;
}
int gcd(int x, int y) {
	int remainder;
	while (y != 0) {
		remainder = x % y;
		if (remainder == 0) {
			break;
		}
		x = y;
		y = remainder;
	}
	return y;
}


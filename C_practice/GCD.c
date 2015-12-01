/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 TM_FILENAME
* @version:	 v1.0
* @Time: 		 2015-07-21 21:45:15
* @Description: 欧几里得最大公因数算法实现
*
+----------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
int gcd(int x, int y);
int main() {
	int x, y;
	printf("请输入x，y\n");
	scanf("%d%d", &x, &y);
	printf("%d与%d的最大公因数是%d\n", x, y, gcd(x, y));

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


/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 test.cpp
* @version:
* @Time:
* @Description:
*
+----------------------------------------------------------
*/
#include <iostream>
using namespace std;
void printArea(int radius = 1);
int main() {
	printArea();
	printArea(4);
	printf("\n");
	system("pause");
	return 0;
}
void printArea(int radius ) {
	printf("radius is %d\n", radius);
}


/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 testttt.cpp
* @version:
* @Time:
* @Description:
*
+----------------------------------------------------------
*/
#include <iostream>

using namespace std;

int main() {
	// unsigned long long int a = -1;
	// // while (++a > 0);
	// cout << "unsigned max: " << a  << endl;

	// long long int b = 1;
	// while (++b > 0);
	// cout << "int max: " << b - 1 << endl;

	signed int c = 1;
	while (++c >= 0);
	cout << "c: " << c  << endl;

	cout << "signed max: " << c - 1 << endl;
	cout << endl;
	system("pause");
	return 0;
}


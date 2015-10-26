/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 4_1.cpp
* @version:
* @Time: 		 2015-08-16 16:33:00
* @Description:
*
+----------------------------------------------------------
*/
#include <iostream>
using namespace std;
int foo(int n) ;

int main() {
	int i = 3;
	double d = 2.0;
	i *= static_cast<int>(d);
	// i *= d;
	cout << i << endl;
	// system("pause");
	cout << foo(100000);
	system("pause");

	return 0;
}

int foo(int n) {
	// cout << n << endl;
	if (n == 0) {
		return 1;
	}
	else
		return n + foo(n - 1);
}

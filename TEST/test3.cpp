/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 test3.cpp
* @version:
* @Time: 		 2015-10-26 21:15:14
* @Description:
*
+----------------------------------------------------------
*/
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <assert.h>

using namespace std;



int main() {
	// freopen("test.in", "r", stdin);
	// freopen("test.out", "w", stdout);
	// cout << sizeof(A) << " " << sizeof(B);
	//
	// int num = 0x22fd7c;
	// *(int *)num = 1000;
	// int *p = (int *)num;
	// cout << p << " " << *p << endl;
	// for (int *i = p, count = 1000; count; count--)
	// 	cout << *i++ << endl;
	cout << *(int *)0x22fd7c;
	cout << endl;
	system("pause");
	return 0;
}


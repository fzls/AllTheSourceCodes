/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 testMultiFileCompile.cpp
* @version:
* @Time:
* @Description:
*
+----------------------------------------------------------
*/
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>
#include "testMFC.h"
#include "testMFC.cpp"

using namespace std;



int main() {
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	foo();
	testMFC test(10);


	cout << endl;
	system("pause");
	return 0;
}

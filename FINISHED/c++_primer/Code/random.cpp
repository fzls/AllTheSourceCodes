/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 random.cpp
* @version:
* @Time: 		 2015-08-23 20:23:24
* @Description:
*
+----------------------------------------------------------
*/
#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int main() {
	uniform_int_distribution<unsigned> u(0, 9999);
	default_random_engine e;
	e.seed(time(0));
	for (int i = 0; i < 10; i++)
		cout << u(e) << endl;

	cout << endl;
	system("pause");
	return 0;
}


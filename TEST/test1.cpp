/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 test1.cpp
* @version:
* @Time: 		 2015-10-07 12:39:20
* @Description:
*
+----------------------------------------------------------
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <functional>
#include <algorithm>

using namespace std;

class Trace
{
private:
	static int count;
	int ct;
public:
	Trace():  ct(count++) {
		cout << "enter " <<  " " << ++ct << endl;
	}
	~Trace() {
		cout << "leave " <<  " " << ct << endl;
	}

};
int Trace::count = 0;
int main() {
	float a = 1e20, b = 1e20, c = 1;
	cout << a - b + c << endl;
	cout << a + c - b << endl;
	cout << -b + c + a << endl;




	cout << endl;
	system("pause");
	return 0;
}

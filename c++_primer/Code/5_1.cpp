/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 5_1.cpp
* @version:
* @Time:
* @Description:
*
+----------------------------------------------------------
*/
#include <iostream>
#include <stdexcept>
using namespace std;

int main() {

	int a, b;
	while (cin >> a >> b) {
		try {
			if (a == b) {
				throw runtime_error("two number must be different");
			}
			cout << a + b << endl;
			break;
		} catch (runtime_error err) {
			cout << err.what() << "\nTry Again? Enter a and b" << endl;
		}

	}

	cout << endl;
	system("pause");
	return 0;
}


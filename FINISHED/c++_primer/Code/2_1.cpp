/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 2_1.cpp
* @version:
* @Time: 		 2015-08-15 16:24:53
* @Description:
*
+----------------------------------------------------------
*/
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

int main() {
	std::vector<int> v;
	for (int i = 0; i < 1000; i++) {
		v.push_back(i);
	}
	// constexpr unsigned sz = 42;
	// unsigned s[sz];
	// unsigned sz2;
	// unsigned s2[sz2];
	// for (int i = 0;; i++) {
	// 	cout << &t[i] << t[i] << endl;
	// 	// system("pause");

	// }
	int b;
	cin >>  b;
	int count = 0;
	auto left = v.begin();
	auto right = v.end();
	auto mid = v.begin() + (right - left) / 2;
	for (; ;) {
		count++;
		if (left > right) {
			cout << b << " not found" << endl;
			break;
		}
		else if (*mid == b) {
			cout << b << " found in index " << (mid - v.begin()) << " in " << count << " steps" ;
			break;
		}
		else if (*mid > b) {
			right = mid - 1;
			mid = left + (right - left) / 2;
		}
		else {
			left = mid + 1;
			mid = left + (right - left) / 2;

		}
	}
	cout << endl;
	system("pause");
	return 0;
}

/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 big_sum.cpp
* @version:
* @Time: 		 2015-08-29 23:34:19
* @Description:
*
+----------------------------------------------------------
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
	// vector version
	int a, n;
	std::vector<int> sum ;
	cin >> a >> n;
	sum.reserve(n + 1);
	int carry = 0;
	for (int i = n; i > 0; i--) {
		sum[i] = (carry + i * a) % 10;
		carry = (carry + i * a) / 10;
	}
	if (n == 0) {
		cout << "0";
	}
	else if (carry == 0) {
		for (int i = 1; i <= n; i++)
			cout << sum[i];
	}
	else {
		sum[0] = carry;
		for (int i = 0; i <= n; i++)
			cout << sum[i];
	}

	//string version
	// int a, n;
	// cin >> a >> n;
	// stringstream ss;
	// string result = "";
	// int carry = 0;
	// for (int i = n; i >= 0; i--) {
	// 	int sum = carry + i * a;
	// 	string temp;
	// 	ss.clear();
	// 	ss << (sum % 10);
	// 	ss >> temp;
	// 	result = temp + result;
	// 	carry = sum / 10;
	// }
	// if (result[0] == '0')
	// 	cout << (n == 0 ? result : result.substr(1));
	// else
	// 	cout << result;

	cout << endl;
	system("pause");
	return 0;
}


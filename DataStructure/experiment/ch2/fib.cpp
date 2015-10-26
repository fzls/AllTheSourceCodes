/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 fib.cpp
* @version:
* @Time:
* @Description:
*
+----------------------------------------------------------
*/
#include <iostream>
#include <vector>
// const int MAX_SIZE = 10000;
// std::vector<int> count(MAX_SIZE, 0) ;

using namespace std;
unsigned long long int fib(int n) {
	// count[n] ++;
	if (n == 0 || n == 1)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}
int main() {
	while (true) {
		int n;
		cin >> n;
		cout << "fib(" << n << ") is " << fib(n) << endl;
		// for (int i = n ; i >= 0; i--) {
		// 	cout << "fib(" << i << ") had been computed " << count[i] << " times" << endl;
		// 	count[i] = 0;
		// }

		cout << endl;
	}

	system("pause");
	return 0;
}


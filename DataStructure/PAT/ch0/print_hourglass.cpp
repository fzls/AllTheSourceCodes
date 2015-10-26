/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 print_hourglass.cpp
* @version:
* @Time: 		 2015-08-25 20:43:13
* @Description:  首先打印出由给定符号组成的最大的沙漏形状，最后在一行中输出剩下没用掉的符号数。
*
+----------------------------------------------------------
*/
#include <iostream>

using namespace std;
void print_hourglass(int lines, char symbol);
int hourglass(int n);
int remain(int n);
int main() {
	int n;
	char symbol;
	cin >> n >> symbol;
	print_hourglass(hourglass(n), symbol);
	cout << remain(n);

	cout << endl;
	system("pause");
	return 0;
}
void print_hourglass(int lines, char symbol) {
	for (int i = lines; i >= 1; --i) {
		for (int j = lines - i; j > 0; --j) {
			cout << " ";
		}
		for (int j = 2 * i - 1; j > 0; --j) {
			cout << symbol;
		}
		cout << endl;
	}

	for (int i = 2; i <= lines; ++i) {
		for (int j = lines - i; j > 0; --j) {
			cout << " ";
		}
		for (int j = 2 * i - 1; j > 0; --j) {
			cout << symbol;
		}
		cout << endl;
	}
}
int hourglass(int n) {
	int k = 0; //if there are five lines,then k is 3;that is if k, then lines=2*k-1;
	while (++k) {
		if (n < 2 * k * k - 1)
			break;
	}
	return k - 1;
}
int remain(int n) {
	return n - 2 * hourglass(n)	* hourglass(n) + 1;
}

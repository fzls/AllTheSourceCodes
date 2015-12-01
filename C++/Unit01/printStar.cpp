/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 printStar.cpp
* @version:	 	 v1.0
* @Time: 		 2015-08-08 20:15:25
* @Description:
*
+----------------------------------------------------------
*/
#include <iostream>
using namespace std;
int main() {
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	int count;
	cin >> count;
	while (count--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				cout << "*";
			}
			cout << endl;
		}
	}
	printf("\n");
	system("pause");
	return 0;
}


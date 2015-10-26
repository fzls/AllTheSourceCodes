/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 footstep.cpp
* @version:
* @Time:
* @Description:
*
+----------------------------------------------------------
*/
#include <iostream>

using namespace std;
unsigned long long int footstep(int n);
unsigned long long int rec_step(int n);
int main() {
	while (true) {

		int n;
		cin >> n;
		cout << footstep(n) << endl;
		// cout << rec_step(n) << endl;
		unsigned long long int a = -1;
		cout << a << endl;
		cout << endl;
	}

	system("pause");
	return 0;
}
unsigned long long int footstep(int n) {
	unsigned long long int first, second, result;
	first = 1; second = 1; result = 1;
	for (int i = 2; i <= n; i++) {
		result = first + second;
		first = second;
		second = result;
	}
	return result;

}
unsigned long long int rec_step(int n)
{
	if (n == 0 || n == 1)
		return 1;
	else
		return rec_step(n - 1) + rec_step(n - 2);
}



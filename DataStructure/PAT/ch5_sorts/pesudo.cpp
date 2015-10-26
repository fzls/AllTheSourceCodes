/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 pesudo.cpp
* @version:
* @Time:
* @Description:
*
+----------------------------------------------------------
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;



int main() {
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);

	quicksort(test);
	bool exists = false;
	for (int i = 0; test[i] < 0; i++) {
		int j = i + 1, k = test.size() - 1, sum = -1;
		while (j < k) {
			sum = test[i] + test[j] + test[k];
			if (sum == 0) {
				exists = true;
				break;
			}
			else if (sum < 0)
				j++;
			else
				k--;
		}
		if (exists)
			break;
	}
	if (exists)
		cout << "exists" << endl;
	else
		cout << "not exists" << endl;


	cout << endl;
	system("pause");
	return 0;
}


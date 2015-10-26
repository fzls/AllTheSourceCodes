/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 PrintN.cpp
* @version:
* @Time: 		 2015-08-25 09:19:15
* @Description:
*
+----------------------------------------------------------
*/
#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

void PrintN(int n);

int main() {
	clock_t t;
	ofstream output("total_time", std::ofstream::out | std::ofstream::app);
	int n;
	output << "test for recursive version" << endl;
	while (true) {
		cin >> n;
		t = clock();
		PrintN(n);
		t = clock() - t;
		output << "it tooks " << t << " clicks" << "( " << ((float)t) / CLOCKS_PER_SEC << " seconds)" << endl;
		printf("it tooks  %d ticks , which is equal to %f seconds \n", (int)t, (float)((float)t / CLOCKS_PER_SEC));

	}

	cout << endl;
	system("pause");
	return 0;
}

// void PrintN(int n) {
// 	for (int i = 1; i <= n; i++) {
// 		cout << i << endl;
// 	}
// }

void PrintN(int n) {
	if (n) {
		PrintN(n - 1);
		cout << n << endl;
	}
}

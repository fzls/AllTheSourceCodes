/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 counting.cpp
* @version:
* @Time: 		 2015-09-13 11:04:14
* @Description:  10-排序4 统计工龄   (20分)
*
+----------------------------------------------------------
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
	// freopen("test.in", "r", stdin);
	// freopen("test.out", "w", stdout);
	int n, year;
	vector<int> working(51, 0) ;
	cin >> n;
	while (n--) {
		cin >> year;
		working[year]++;
	}
	for (int i = 0; i <= 50; i++)
		if (working[i] != 0)
			cout << i << ":" << working[i] << endl;


	// cout << endl;
	// system("pause");
	return 0;
}


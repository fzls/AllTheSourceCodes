/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 p1.cpp
* @version:
* @Time: 		 2015-10-10 13:19:46
* @Description:  rob bank
*
+----------------------------------------------------------
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <random>
#include <ctime>

using namespace std;
void initialize(vector<int>& banks);
void findMaxPlan(vector<int>& banks);


int main() {
	// freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	while (true) {
		int n;
		cin >> n;
		vector<int> banks(n, 0) ;
		initialize(banks);
		findMaxPlan(banks);
	}


	cout << endl;
	system("pause");
	return 0;
}

void initialize(vector<int>& banks) {
	uniform_int_distribution<unsigned> u(0, 100);
	default_random_engine e;
	e.seed(time(0));

	for (std::vector<int>::iterator i = banks.begin(); i != banks.end(); ++i)
	{
		*i = u(e) ;//随机生成0~100的数字
	}
	int count = 0;
	for (std::vector<int>::iterator i = banks.begin(); i != banks.end(); ++i)
	{
		cout << *i << (++count % 5 == 0 ? '\n' : ' ') ;
	}
}

void findMaxPlan(vector<int>& banks) {
	int n = static_cast<int>(banks.size());
	vector<int> robs(n, 0) ;
	vector<int> router(n, 0);
	robs[0] = banks[0];
	robs[1] = max(banks[0], banks[1]);
	for (int i = 2; i < n; i++) {
		if (max(robs[i - 1], robs[i - 2] + banks[i] ) == robs[i - 1] )
			router[i] = i - 1;
		else
			router[i] = i - 2;
		robs[i] = max(robs[i - 1], robs[i - 2] + banks[i] );// 使用动态规划（取前一个或者前两个+本身的最大值）
	}
	cout << endl << "the max is : " << robs[n - 1] << endl;
	cout << "the reverse path is :" << endl;
	if (router[n - 1] == n - 3)
		cout << n - 1 << " " << banks[n - 1] << " " << robs[n - 1] << endl;
	for (int i = n - 1; i > 1; i -= 2)
		cout << router[i] << " " << banks[router[i]] <<
		     " " << robs[router[i]] << endl;
	cout << endl << endl;
}
/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 test.cpp
* @version:
* @Time:
* @Description:
*
+----------------------------------------------------------
*/
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>
#include <set>

using namespace std;

class Solution {
public:
	bool isHappy(int n) {
		std::set<int> occured ;
		int temp;
		int count = 0;
		cout << n << "\t" ;
		while (true) {
			// cout << n << " -> ";
			occured.insert(n);
			temp = n;
			n = 0;
			while (temp) {
				n += (temp % 10) * (temp % 10);
				temp /= 10;
			}
			count++;
			// if(n<10||occured.find(n)!=occured.end())
			if (occured.find(n) != occured.end())
				break;
		}
		// cout<<n<<endl;
		cout << "counts: " << count << endl;
		return n == 1;
	}
};


int main() {
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	Solution solution;
	clock_t _time = clock();
	default_random_engine _e(_time);
	int factor = 1;
	for (int j = 1; j <= 10; ++j, factor *= 10)
		for (int i = 1; i < 2000; ++i)
			solution.isHappy(factor + _e() % (9 * factor));
	// if (solution.isHappy(i))
	// 	cout << i << " is a happy number" << endl;
	// else
	// 	cout << i << " is NOT a happy number" << endl;
	cout << endl;
	system("pause");
	return 0;
}

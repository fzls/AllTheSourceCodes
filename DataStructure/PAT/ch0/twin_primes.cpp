/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 twin_primes.cpp
* @version:
* @Time: 		 2015-08-25 21:18:06
* @Description:  现给定任意正整数N (< 105)，请计算不超过N的满足猜想的素数对的个数。
*
+----------------------------------------------------------
*/
#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <fstream>

using namespace std;

// bool isprime(int n);

// int main() {
// 	clock_t t;
// 	ofstream output("twin_prime.txt", ofstream::app);
// 	output << "--------------------------" << endl;
// 	output << "test for a worse version" << endl;
// 	int n, count ;
// 	while (cin >> n) {
// 		count = 0;
// 		t = clock();
// 		for (int i = 2; i < n - 1; i++)
// 			if (isprime(i) && isprime(i + 2))
// 				count++;
// 		t = clock() - t;
// 		output << count << endl << "N is " << n << " run time is: " << ((float)t) / CLOCKS_PER_SEC << " seconds)";
// 		output << endl;
// 	}

// 	system("pause");
// 	return 0;
// }
// bool isprime(int n) {
// 	bool prime = true;
// 	int sqrt_n = (int)sqrt(n);
// 	for (int i = 2; i <= sqrt_n; i++)
// 		if (n % i == 0) {
// 			prime = false;
// 			break;
// 		}
// 	return prime;
// }

bool isprime(int n, const vector<int>& prime);

int main() {
	clock_t t;
	ofstream output("twin_prime.txt", ofstream::app);
	output << "test for better version" << endl;
	int n, count;
	std::vector<int> prime ;
	while (cin >> n) {
		prime.push_back(2);
		count = 0;
		t = clock();
		for (int i = 3; i <= n ; i += 2)
			if (isprime(i, prime)) {
				prime.push_back(i);
			}
		for (auto i = prime.cbegin(); i != prime.cend() - 1; ++i)
			if (*(i + 1) - *i == 2)
				++count;
		t = clock() - t;
		output << count << endl << "N is " << n << " run time is: " << ((float)t) / CLOCKS_PER_SEC << " seconds)";
		output << endl;
		prime.clear();
	}

	system("pause");
	return 0;
}
bool isprime(int n, const vector<int>& prime) {
	bool is_prime = true;
	int sqrt_n = (int)sqrt(n);
	for (int i = 0; prime[i] <= sqrt_n; i++)
		if (n % prime[i] == 0) {
			is_prime = false;
			break;
		}
	return is_prime;
}

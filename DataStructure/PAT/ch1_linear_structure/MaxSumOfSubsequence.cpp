/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 MaxSumOfSubsequence.cpp
* @version:
* @Time: 		 2015-08-25 10:38:40
* @Description: loop version , divide and conquer version and online version of finding max sum of
* subsequence.
*
+----------------------------------------------------------
*/
#include <iostream>
#include <vector>

using namespace std;
int findmax_loop_version(int n, const vector<int>& sequence);
int findmax_DAC_version(int lhs, int rhs, const vector<int>& sequence);
int findmax_N_version(int lhs, int rhs, const vector<int>& sequence);
int max(int l, int r, int m);
int max(int a, int b);
int find_max_mid(int lhs, int rhs, int mid, const std::vector<int>& sequence);

int main() {
	int n, number;
	cin >> n;
	std::vector<int> sequence ;

	for (int i = 0; i < n; i++) {
		cin >> number;
		sequence.push_back(number);
	}
	// cout << "max is " << findmax(n, sequence);
	// cout << "loop: " << findmax_loop_version(n, sequence) << endl;
	// cout << "divide and conquer: " << findmax_DAC_version(0, n - 1, sequence) << endl;
	// cout << "N version: " << findmax_N_version(0, n - 1, sequence) << endl;
	cout  << findmax_N_version(0, n - 1, sequence);


	// cout << endl;
	// system("pause");
	return 0;
}

int findmax_N_version(int lhs, int rhs, const vector<int>& sequence) {
	int max = 0, sofar = 0;
	for (int i = lhs; i <= rhs; i++) {
		sofar += sequence[i];
		if (sofar > max)
			max = sofar;
		if (sofar < 0)
			sofar = 0;
	}
	return max;
}


int findmax_DAC_version(int lhs, int rhs, const vector<int>& sequence) {
	if (lhs == rhs) {
		if (sequence[lhs] > 0)
			return sequence[lhs];
		else
			return 0;
	}
	else {
		int mid = lhs / 2 + rhs / 2;
		int max_left = findmax_DAC_version(lhs, mid, sequence);
		int max_right = findmax_DAC_version(mid + 1, rhs, sequence);
		int max_mid = find_max_mid(lhs, rhs, mid, sequence);
		return max(max_left, max_right, max_mid);
	}

}

int max(int a, int b) {
	return a >= b ? a : b;
}
int max(int l, int r, int m) {
	return max(max(l, r), m);
}

int find_max_mid(int lhs, int rhs, int mid, const std::vector<int>& sequence) {
	int max_mid_l = 0;
	int max_mid_r = 0;
	int sum;
	sum = 0;
	for (int i = mid; i >= lhs; i--) {
		sum += sequence[i];
		if (sum > max_mid_l)
			max_mid_l = sum;
	}
	sum = 0;
	for (int i = mid + 1; i <= rhs; i++) {
		sum += sequence[i];
		if (sum > max_mid_r)
			max_mid_r = sum;
	}
	return max_mid_l + max_mid_r;
}


int findmax_loop_version(int n, const vector<int>& sequence) {
	// unsigned int temp = -1;
	// int sumi = 0, max = -(int)(temp / 2 - 1);
	int sumi = 0, max = 0;
	for (int i = 0; i < n; i++) {
		sumi = 0;
		for (int j = i; j < n; j++) {
			sumi += sequence[j];
			if (sumi > max) {
				max = sumi;
			}
		}
	}
	return max;
}


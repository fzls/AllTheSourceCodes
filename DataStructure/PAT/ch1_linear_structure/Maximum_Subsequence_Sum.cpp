/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 Maximum Subsequence Sum.cpp
* @version:
* @Time:
* @Description:  Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.
*
+----------------------------------------------------------
*/
#include <iostream>
#include <vector>

using namespace std;
int findmax_loop_version(int n, const vector<int>& sequence, int &max_start, int &max_end);
int findmax_DAC_version(int lhs, int rhs, const vector<int>& sequence);
int findmax_N_version(int lhs, int rhs, const vector<int>& sequence, int &max_start, int &max_end);
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
	int max_start = sequence[0] , max_end = sequence[n - 1] ;

	// cout << "max is " << findmax(n, sequence);
	// cout << "loop: " << findmax_loop_version(n, sequence) << endl;
	// cout << "divide and conquer: " << findmax_DAC_version(0, n - 1, sequence) << endl;
	// cout << "N version: " << findmax_N_version(0, n - 1, sequence) << endl;
	// cout << findmax_loop_version(n, sequence, max_start, max_end) ;
	// cout << " " << max_start << " " << max_end ;

	cout  << findmax_N_version(0, n - 1, sequence, max_start, max_end);
	cout << " " << max_start << " " << max_end ;


	// cout << endl;
	// system("pause");
	return 0;
}

int findmax_N_version(int lhs, int rhs, const vector<int>& sequence, int &max_start, int &max_end) {
	int max = 0, sofar = 0, start_temp = 0;
	for (int i = lhs; i <= rhs; i++) {
		sofar += sequence[i];
		if (sofar > max) {
			max = sofar;
			max_start = sequence[start_temp];
			max_end = sequence[i];
		}

		if (sofar < 0) {
			sofar = 0;
			start_temp = i + 1;
		}
	}
	int n = sequence.size();
	for (int i = 0; i < n; i++)
		if (sequence[i] == 0 && max == 0) {
			max_start = max_end = 0;
			break;
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


int findmax_loop_version(int n, const vector<int>& sequence, int &max_start, int &max_end) {
	// unsigned int temp = -1;
	// int sumi = 0, max = -(int)(temp / 2 - 1);
	int sumi = 0, max = 0;
	for (int i = 0; i < n; i++) {
		sumi = 0;
		for (int j = i; j < n; j++) {
			sumi += sequence[j];
			if (sumi > max) {
				max = sumi;
				max_start = sequence[i];
				max_end = sequence[j];
			}
		}
	}
	for (int i = 0; i < n; i++)
		if (sequence[i] == 0 && max == 0) {
			max_start = max_end = 0;
			break;
		}
	return max;
}



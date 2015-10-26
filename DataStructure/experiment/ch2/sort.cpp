/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 sort.cpp
* @version:
* @Time: 		 2015-08-31 18:20:45
* @Description: test efficiency diffences between selection sort, bubble sort and merge sort;
*
+----------------------------------------------------------
*/
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <iomanip>

using namespace std;

void selection_sort(vector<int>& tosort);
void bubble_sort(vector<int>& tosort);
void merge_sort(vector<int>& tosort);
void merge(vector<int>& tosort, vector<int>& left, vector<int>& right);

void swap(int& a, int& b);

int main() {
	clock_t time = clock();
	while (true) {
		int n;
		cin >> n;
		std::vector<int> temp ;

		default_random_engine e(time);
		for (int i = 0; i < n; i++)
			temp.push_back(e());
		std::vector<int> tosort ;

		tosort = temp;
		time = clock();
		merge_sort(tosort);
		time = clock() - time;
		cout << left << setw(15) << "merge_sort" << " numbers: " << n << " : Clicks: " << time << "    " << ((float)time) / CLOCKS_PER_SEC << " seconds" << endl;

		// tosort = temp;
		// time = clock();
		// selection_sort(tosort);
		// time = clock() - time;
		// cout << left << setw(15) << "selection_sort" << " numbers: " << n << " : Clicks: " << time << "    " << ((float)time) / CLOCKS_PER_SEC << " seconds" << endl;

		// tosort = temp;
		// time = clock();
		// bubble_sort(tosort);
		// time = clock() - time;
		// cout << left << setw(15) << "bubble_sort" << " numbers: " << n << " : Clicks: " << time << "    " << ((float)time) / CLOCKS_PER_SEC << " seconds" << endl;


		cout << endl;
	}
	system("pause");
	return 0;

}

void swap(int& a, int& b) {
	int temp;
	temp = a; a = b; b = temp;
}

void selection_sort(vector<int>& tosort) {
	int length =  static_cast<int>(tosort.size());
	int min_index;
	for (int i = 0; i < length; i++) {
		min_index = i;
		for (int j = i; j < length; j++) {
			if (tosort[j] < tosort[min_index])
				min_index = j;
		}
		swap(tosort[min_index], tosort[i]);
	}
}
void bubble_sort(vector<int>& tosort) {
	int length = static_cast<int>(tosort.size());
	for (int i = 0; i < length; i++) {
		for (int j = length - 1; j > i; j--)
			if (tosort[j] < tosort[j - 1])
				swap(tosort[j], tosort[j - 1]);
	}

}
void merge_sort(vector<int>& tosort) {
	if (tosort.size() > 1) {
		// int start = 0;
		// int length = tosort.size() - 1;
		// int middle = start + (length - start) / 2;

		// std::vector<int> left;
		// for (int i = start; i <= middle; i++)
		// 	left.push_back(tosort[i]);
		// std::vector<int> right;
		// for (int i = middle + 1; i <= length; i++)
		// 	right.push_back(tosort[i]);

		auto start = tosort.begin();
		auto end = tosort.end() - 1;
		auto middle = start + (end - start) / 2;

		std::vector<int> left;
		left.assign(start, middle + 1);

		std::vector<int> right;
		right.assign(middle + 1, end + 1);

		merge_sort(left);
		merge_sort(right);
		merge(tosort, left, right);

	}
}
void merge(vector<int>& tosort, vector<int>& left, vector<int>& right) {
	auto i = tosort.begin();
	auto j = left.begin();
	auto k = right.begin();
	while (i != tosort.end() && j != left.end() && k != right.end()) {
		if (*j <= *k)
			*i++ = *j++;
		else
			*i++ = *k++;
	}
	if (j != left.end()) {
		while (i != tosort.end())
			*i++ = *j++;
	}
	else {
		while (i != tosort.end())
			*i++ = *k++;
	}

}

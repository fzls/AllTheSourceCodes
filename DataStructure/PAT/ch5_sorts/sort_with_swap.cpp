/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 sort_with_swap.cpp
* @version:
* @Time: 		 2015-09-13 13:17:55
* @Description:  10-排序6 Sort with Swap(0, i)   (25分)
*
+----------------------------------------------------------
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_i(vector<int> &data, int value);
int find_first_not_match(vector<int> &data, int &start);

int main() {
	// freopen("test.in", "r", stdin);
	// freopen("test.out", "w", stdout);
	int n;
	cin >> n;
	int  count = 0, temp, swap_index;

	vector<int> data(n);
	for (int i = 0; i < n; i++) {
		cin >> temp;
		data[temp] = i;
	}
	int start = 1; //tag for the sorted part end, so that the total time will be linear
	while (true) {
		if (data[0] == 0) {
			swap_index = find_first_not_match(data, start);
			if (swap_index == -1)
				break;
			else {
				swap(data[0], data[swap_index]);
				count++;
			}
		}
		swap(data[0], data[data[0]]);
		count++;
	}
	cout << count;
	cout << endl;

	// for (int k : data)
	// 	cout << k << " ";

	// system("pause");
	return 0;
}
// int find_i(vector<int> &data, int value) {
// 	int n = static_cast<int>(data.size());
// 	for (int i = 0; i < n; i++)
// 		if (data[i] == value)
// 			return i;
// 	return -1;
// }
int find_first_not_match(vector<int> &data, int& start) {
	int n = static_cast<int>(data.size());
	for (int i = start; i < n; i++) {
		if (data[i] != i)
			return i;
		start++;
	}
	return -1;
}

// int main() {
// 	// freopen("test.in", "r", stdin);
// 	// freopen("test.out", "w", stdout);
// 	int n;
// 	cin >> n;
// 	int zero_index, swap_index, count = 0;
// 	map<int, int> value2index ;

// 	vector<int> data(n);
// 	for (int i = 0; i < n; i++) {
// 		cin >> data[i];
// 		value2index.insert(pair<int, int>(data[i], i));
// 		// cout << data[i] << " " << value2index[data[i]] << endl;
// 	}
// 	zero_index = value2index[0];
// 	// cout << zero_index;
// 	while (true) {
// 		if (zero_index == 0) {
// 			swap_index = find_first_not_match(data);
// 			if (swap_index == -1)
// 				break;
// 			else {
// 				value2index[0] = swap_index;
// 				value2index[data[swap_index]] = 0;
// 				swap(data[zero_index], data[swap_index]);
// 				count++;
// 				zero_index = swap_index;
// 			}
// 		}
// 		swap_index = value2index[zero_index];
// 		value2index[0] = swap_index;
// 		swap(data[zero_index], data[swap_index]);
// 		count++;
// 		zero_index = swap_index;
// 	}
// 	cout << count;
// 	cout << endl;

// 	// for (int k : data)
// 	// 	cout << k << " ";

// 	// system("pause");
// 	return 0;
// }
// // int find_i(vector<int> &data, int value) {
// // 	int n = static_cast<int>(data.size());
// // 	for (int i = 0; i < n; i++)
// // 		if (data[i] == value)
// // 			return i;
// // 	return -1;
// // }
// int find_first_not_match(vector<int> &data) {
// 	int n = static_cast<int>(data.size());
// 	for (int i = 0; i < n; i++) {
// 		if (data[i] != i)
// 			return i;
// 	}
// 	return -1;
// }



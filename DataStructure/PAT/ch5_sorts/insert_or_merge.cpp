/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 insert_or_merge.cpp
* @version:
* @Time: 		 2015-09-13 09:17:10
* @Description:  09-排序2 Insert or Merge   (25分)
*
+----------------------------------------------------------
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void merge(vector<int> &part, vector<int> &temp, int first, int mid, int last );


int main() {
	// freopen("insert_or_merge.in", "r", stdin);
	// freopen("insert_or_merge.out", "w", stdout);
	int n;
	cin >> n;
	vector<int> init(n), part(n) ;
	for (int i = 0; i < n; i++)
		cin >> init[i];
	for (int i = 0; i < n; i++)
		cin >> part[i];

	int length = 1;
	bool is_merge;
	while (length < n) {
		vector<int> temp(n) ;
		int j;
		for (j = 0; j <= n - 2 * length; j += 2 * length)
			merge(init, temp, j, j + length - 1, j + 2 * length - 1);
		if (j + length < n)
			merge(init, temp, j, j + length - 1, n - 1);
		else
			for (int k = j; k < n; k++)
				temp[k] = init[k];
		init = temp;
		is_merge = true;
		for (int f = 0; f < n; f++)
			if (init[f] != part[f]) {
				is_merge = false;
				break;
			}
		if (is_merge)
			break;
		length *= 2;
	}
	string algorithm("Insertion Sort");

	if (is_merge)
		algorithm = "Merge Sort";

	if (algorithm == "Insertion Sort") {
		int i;
		for (i = n - 1; i >= 0 && init[i] == part[i]; i--);
		int temp = part[i + 1], j;
		for (j = i + 1; j > 0 && temp < part[j - 1]; j--)
			part[j] = part[j - 1];
		part[j] = temp;
	}
	else {
		length *= 2;
		vector<int> temp(n) ;
		int j;
		for (j = 0; j <= n - 2 * length; j += 2 * length)
			merge(part, temp, j, j + length - 1, j + 2 * length - 1);
		if (j + length < n)
			merge(part, temp, j, j + length - 1, n - 1);
		else
			for (int k = j; k < n; k++)
				temp[k] = part[k];
		part = temp;
	}


	cout << algorithm << endl;
	for (int k = 0; k < n; k++)
		cout << part[k] << (k == n - 1 ? "" : " ");
	cout << endl;
// system("pause");
	return 0;
}
void merge(vector<int> &part, vector<int> &temp, int first, int mid, int last ) {
	int i = first, j = mid + 1, index = first;
	while (i <= mid && j <= last)
		if (part[i] <= part[j])
			temp[index++] = part[i++];
		else
			temp[index++] = part[j++];
	while (i <= mid)
		temp[index++] = part[i++];
	while (j <= last)
		temp[index++] = part[j++];

}

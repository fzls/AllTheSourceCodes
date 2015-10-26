/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 path_in_heap.cpp
* @version:
* @Time: 		 2015-09-05 14:30:23
* @Description:  05-树7 堆中的路径   (25分)
* 对输入中给出的每个下标i，在一行中输出从H[i]
* 到根结点的路径上的数据。数字间以1个空格分隔，行末不得有多余空格。
*
+----------------------------------------------------------
*/
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
// void moveDown(vector<int> &heap, int lower, int upper );
int main() {
	int n, m, data;
	std::vector<int> heap ;
	cin >> n >> m;
	heap.push_back(INT_MIN);
	for (int i = 0; i < n; i++) {
		cin >> data;
		heap.push_back(data);
	}
	for (int i = 1; i <= n; i++) {
		int index = i;
		while (heap[index] < heap[index / 2]) {
			swap(heap[index], heap[index / 2]);
			index /= 2;
		}
	}

	for (int i = 0; i < m; i++) {
		int index;
		cin >> index;
		while (index != 0) {
			cout << heap[index] << (index == 1 ? "" : " ");
			index /= 2;
		}
		cout << endl;
	}

	// for (int i = (n - 1) / 2; i >= 0; i--) {
	// 	moveDown(heap, i, n - 1);
	// }

	// cout << endl;
	// system("pause");
	return 0;
}
// void moveDown(vector<int> &heap, int lower, int upper ) {
// 	int least = 2 * lower + 1;
// 	while (least <= upper) {
// 		if (least < upper && heap[least + 1] < heap[least])
// 			least++;

// 		if (heap[least] < heap[lower]) {
// 			swap(heap[least], heap[lower]);
// 			lower = least;
// 			least = 2 * lower + 1;
// 		}
// 		else
// 			least = upper + 1;
// 	}
// }


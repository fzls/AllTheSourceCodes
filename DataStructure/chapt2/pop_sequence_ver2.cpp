/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 pop_sequence_ver2.cpp
* @version:
* @Time: 		 2015-08-28 20:50:38
* @Description:  02-线性结构4. Pop Sequence (25)
* by simulating the instack and outstack to determine whether a permutation can happen.
*
+----------------------------------------------------------
*/
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool check(vector<int>& tocheck, int stack_capacity);

int main() {
	std::vector<bool> result ;

	int m, n, k;
	cin >> m >> n >> k;
	while (k--) {
		std::vector<int> permutation ;
		int number;
		for (int i = 0; i < n; i++) {
			cin >> number;
			permutation.push_back(number);
		}
		result.push_back(check(permutation, m));
	}
	for (auto is_permutation_k : result) {
		if (is_permutation_k)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}

bool check(vector<int>& tocheck, int stack_capacity) {
	stack<int> Stack;
	bool not_out_of_bounds = true;
	int m = 1;
	for (int i = 0; i < static_cast<int>(tocheck.size()); i++) {
		while (m <= tocheck[i]) {
			if (static_cast<int>(Stack.size()) >= stack_capacity) {
				not_out_of_bounds = false;
				break;
			}
			Stack.push(m);
			++m;
		}
		if (Stack.top() == tocheck[i])
			Stack.pop();
		if (!not_out_of_bounds)
			break;
	}

	return not_out_of_bounds && Stack.empty();
}

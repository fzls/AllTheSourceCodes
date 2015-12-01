/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 pop_sequence.cpp
* @version:
* @Time: 		 2015-08-28 19:09:07
* @Description:  02-线性结构4. Pop Sequence (25)
*
+----------------------------------------------------------
*/
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool check(vector<int>& tocheck, stack<int> Stack, int capacity);
// void pop_permutation(int length, int capacity);
// void recursive_pop(stack<int> Stack, int capacity, int push_time, int push_max_time);
int main() {
	int m, n, k;
	// M (the maximum capacity of the stack), N (the length of push sequence), and K (the number of pop sequences to be checked)
	cin >> m >> n >> k;
	stack<int> Stack;
	std::vector<bool> result ;

	while (k--) {
		std::vector<int> permutation ;
		int number;
		for (int i = 0; i < n; i++) {
			cin >> number;
			permutation.push_back(number);
		}
		result.push_back(check(permutation, Stack, m));
		// if (check(permutation, Stack, m))
		// 	cout << "YES" << endl;
		// else
		// 	cout << "NO" << endl;
	}
	for (auto k : result) {
		if (k)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	// cout << endl;
	// system("pause");
	return 0;
}
bool check(vector<int>& tocheck, stack<int> Stack, int capacity) {
	bool is_permutation = true;
	if (capacity < tocheck.size()) {
		for (int i = 0; i < tocheck.size() - capacity; i++)
			if (tocheck[i] > capacity + i) {
				is_permutation = false;
				break;
			}
		//other determine method
		std::vector<int> trans ;
		trans.resize(tocheck.size());
		for (int i = 0; i < tocheck.size(); i++)
			trans[tocheck[i]] = i;
		for (int i = tocheck[0] - 2; i >= 0; i++)
			if (trans[i] > trans[i + 1]) {
				is_permutation = false;
				break;
			}
	}
	else {
		//other determine method
		std::vector<int> trans ;
		trans.resize(tocheck.size());
		for (int i = 0; i < tocheck.size(); i++)
			trans[tocheck[i]] = i;
		for (int i = tocheck[0] - 2; i >= 0; i++)
			if (trans[i] > trans[i + 1]) {
				is_permutation = false;
				break;
			}


	}
	return is_permutation;
}

// void pop_permutation(int length, int capacity) {
// 	stack<int> Stack;
// 	int push_max_time = length;
// 	int push_time = 0;
// 	recursive_pop( Stack, capacity, push_time, push_max_time);
// }
// void recursive_pop(stack<int> Stack, int capacity, int push_time, int push_max_time) {

// 	if (Stack.empty() && push_time != push_max_time) {
// 		Stack.push(push_time + 1);
// 	}
// 	else if (push_time == push_max_time) {
// 		while (!Stack.empty()) {
// 			cout << Stack.top() << " ";
// 			Stack.pop();
// 		}
// 		cout << endl;
// 	}
// 	else {
// 		if (Stack.size() < capacity) {
// 			Stack.push(push_time + 1);
// 			recursive_pop(Stack, capacity, push_time + 1, push_max_time);
// 			Stack.pop();
// 		}

// 		cout << Stack.top() << " ";
// 		Stack.pop();
// 		recursive_pop(Stack, capacity, push_time, push_max_time);
// 	}

// }

/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 permute.cpp
* @version:	 	 v1.0
* @Time: 		 2015-08-16 21:47:05
* @Description:  use recursion to implement printing all possible permutations
*
+----------------------------------------------------------
*/
#include <iostream>
#include <string>
using namespace std;

static int count = 1;

void listPermutation(string s);
void recPermutation(string completed, string remaining);

int main() {
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	string s;
	cin >> s;
	listPermutation(s);

	cout << endl;
	system("pause");
	return 0;
}

void listPermutation(string s) {
	recPermutation("", s);
}
void recPermutation(string completed, string remaining) {
	if (remaining.size() == 0) {
		// cout << count++ << '\t' << completed  << endl;
		cout << completed  << endl;
	}
	else
		for (decltype(completed.size()) i = 0; i < remaining.size(); i++) {
			string completed_ = completed  + remaining[i] + " ";
			string remaining_ = remaining.substr(0, i) + remaining.substr(i + 1);
			recPermutation(completed_, remaining_);
		}
}

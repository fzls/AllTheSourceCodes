/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 permuteImp.cpp
* @version:
* @Time:
* @Description:
*
+----------------------------------------------------------
*/
#include "permute.h"
#include <iostream>
using namespace std;
extern static count;
void listPermutation(string s) {
	recPermutation("", s);
}
void recPermutation(string completed, string remaining) {
	if (remaining.size() == 0) {
		cout << count++ << '\t' << completed  << endl;
	}
	else
		for (decltype(completed.size()) i = 0; i < remaining.size(); i++) {
			string completed_ = completed + remaining[i];
			string remaining_ = remaining.substr(0, i) + remaining.substr(i + 1);
			recPermutation(completed_, remaining_);
		}
}


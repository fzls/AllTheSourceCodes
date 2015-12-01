/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 Subsets.cpp
* @version:
* @Time: 		 2015-08-20 18:49:25
* @Description:  subsets
*
+----------------------------------------------------------
*/
#include <iostream>
#include "Subsets.h"
#include <fstream>


using namespace std;
static int count;
static ofstream output;
int main() {
	output.open("subset");
	string test;
	while (cin >> test) {
		ListSubsets(test);
		output << "-------------------------------" << endl;
	}

	output << endl;
	system("pause");
	return 0;
}

void ListSubsets(std::string str) {
	count = 1;
	RecSubsets("", str);
}
void RecSubsets(std::string dealt, std::string remaining ) {
	if (remaining.size() == 0) {
		output << "No." << count++ << "\t" << (dealt.size() == 0 ? "null set" : dealt) << endl;
	}
	else {
		RecSubsets(dealt + remaining[0], remaining.substr(1));
		RecSubsets(dealt, remaining.substr(1));
	}
}

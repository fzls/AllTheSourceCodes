/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 10_1.cpp
* @version:
* @Time: 		 2015-08-19 14:30:08
* @Description:
*
+----------------------------------------------------------
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>


using namespace std;

int main() {
	std::unordered_map<string, size_t> word_count ;
	ofstream output("count_words", fstream::out );

	string word;
	while (cin >> word) {
		++word_count[word];
	}
	output << word_count.bucket_count() << endl;
	for (const auto &w : word_count) {
		output << w.first << "	occurs	" << w.second << ((w.second > 1) ? "	times" : "	time") << endl;
	}

	output << endl;
	system("pause");
	return 0;
}

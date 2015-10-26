/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 string_test.cpp
* @version:
* @Time: 		 2015-08-28 00:57:24
* @Description:
*
+----------------------------------------------------------
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
	string s1("hello") , s2("hello") , s3("0"), s4 = "test", s5 = {"test"};
	cout << "s1.compare(s2)" << s1.compare(s2) << endl;
	cout << "(s4 == s5) " << (s4 == s5) << endl;
	cout << "s1.size()" << s1.size() << endl;
	cout << s4.max_size() << endl;
	cout << s5.max_size() << endl;
	std::string str ("Test string");
	str += s5;
	std::cout << "size: " << str.size() << "\n";
	std::cout << "length: " << str.length() << "\n";
	std::cout << "capacity: " << str.capacity() << "\n";
	std::cout << "max_size: " << str.max_size() << "\n";

	cout << endl;
	system("pause");
	return 0;
}


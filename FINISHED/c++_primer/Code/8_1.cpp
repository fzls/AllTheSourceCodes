/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 8_1.cpp
* @version:
* @Time: 		 2015-08-18 21:04:53
* @Description:
*
+----------------------------------------------------------
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


// istream &input(istream &in);
// istream &input(istream &in) {
// 	std::string buf;
// 	while (in >> buf) {
// 		// cout << buf << endl;
// 		cout << unitbuf;
// 		cout << buf << flush;
// 		cout << buf << ends;

// 	}
// 	in.clear();
// 	return in;
// }
int main() {
	ofstream out("file1");
	ofstream out2("file1", ofstream::out);
	ofstream out3("file1", ofstream::out | ofstream::trunc);
	out3 << "this is a test " << 512134 << " OK? ";

	ofstream app("file2", ofstream::app);
	ofstream app2("file2", ofstream::out | ofstream::app);

	fstream test("test", ofstream::out );
	test << 1243 << " hello this is a test" << " \n OK~" << endl;
	test.close();
	ifstream test2;
	test2.open("test", ifstream::in);
	int a;
	string b;
	test2 >> a >> b;
	cout << a << b;

	// int a;
	// cin.tie(&cout);
	// auto old_state = cin.rdstate();
	// cin.clear();
	// input(cin);
	// // process_input(cin);
	// cin >> a;
	// cin.setstate(old_state);
	// cout << cin.rdstate();
	cout << endl;
	system("pause");
	return 0;
}


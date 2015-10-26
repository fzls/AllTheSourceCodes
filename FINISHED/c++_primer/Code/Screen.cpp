/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 Screen.cpp
* @version:
* @Time: 		 2015-08-18 13:22:11
* @Description:
*
+----------------------------------------------------------
*/
#include <iostream>
#include "Screen.h"

using namespace std;

inline Screen &Screen::move(pos r, pos c) {
	pos row = r * width;
	cursor = row + c;
	return *this;
}

char Screen::get(pos r, pos c)const {
	pos row = r * width;
	return contents[row + c];
}


int main() {
	cout << "before:	" << Screen::test << endl;
	Screen::staticTest();
	cout << "after:	" << Screen::test << endl;

	Screen myscreen(10, 20, 'r');
	char ch = myscreen.get(); cout << ch << endl;
	ch = myscreen.get(0, 0); cout << ch << endl;
	cout << "before:	" << myscreen.test << endl;
	myscreen.staticTest();
	cout << "after:	" << myscreen.test << endl;
	cout << myscreen.nonstaticTest() << endl;

	cout << endl;
	system("pause");
	return 0;
}


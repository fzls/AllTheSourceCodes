/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:    test.cpp
* @version:
* @Time:
* @Description:
*
+----------------------------------------------------------
*/
#include <iostream>
#include <fstream>
using namespace std;
int main() {
    fstream inout;
    inout.open("123.dat", ios::out | ios::binary);
    cout << "tellp = " << inout.tellp() << " tellg = " << inout.tellg() << endl;
    cout << "tellg = " << inout.tellg() << " tellp = " << inout.tellp() << endl; // tellp 和 tellg 交换顺序
    inout.write("12345", 5);
    cout << "tellp = " << inout.tellp() << " tellg = " << inout.tellg() << endl;
    cout << "tellg = " << inout.tellg() << " tellp = " << inout.tellp() << endl; // tellp 和 tellg 交换顺序

    cout << endl;
    system("pause");
    return 0;
}


/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 13_1.cpp
* @version:
* @Time: 		 2015-08-20 16:38:09
* @Description:
*
+----------------------------------------------------------
*/
#include <iostream>
#include <string>

using namespace std;

class Test
{
private:
	string dvd;
	double price;
	int number;
	double total;
public:
	Test(string d = "default" , double p = 0.0, int n = 0, double t = 0): dvd(d), price(p), number(n), total(t) {}
	~Test() {};

	friend ostream &operator<<(ostream &os, const Test &test);
	friend istream &operator>>(istream &is, Test &test);
	friend bool operator==(const Test &lhs, const Test &rhs);
	friend bool operator!=(const Test &lhs, const Test &rhs);
	// friend double operator<(const Test &lhs, const Test &rhs);
	// friend Test &operator+(const Test &lhs, const Test &rhs);
	// friend Test &operator-(const Test &lhs, const Test &rhs);
	Test &operator++();
	Test operator++(int);

	Test &operator--();
	Test operator--(int);

};
Test &Test::operator++() {
	++number;
	total = number * price;
	return *this;
}

Test Test::operator++(int) {
	Test test = *this;
	++number;
	total = number * price;

	return test;
}

Test Test::operator--(int) {
	Test test = *this;
	--number;
	total = number * price;

	return test;
}

Test &Test::operator--() {
	--number;
	total = number * price;

	return *this;
}

bool operator==(const Test &lhs, const Test &rhs) {
	return lhs.dvd == rhs.dvd &&
	       (lhs.price - rhs.price) < 10e-6 &&
	       lhs.number == rhs.number &&
	       (lhs.total - rhs.total) < 10e-6;
}

bool operator!=(const Test &lhs, const Test &rhs) {
	return !(lhs == rhs);
}


ostream &operator<<(ostream &os, const Test &test) {
	os << "DVD title: " << test.dvd << " " << " Price " << test.price << " Number " << test.number
	   << " Total " << test.total << endl;
	return os;
}


istream &operator>>(istream &is, Test &test) {
	is >> test.dvd >> test.price >> test.number ;
	if (is)
		test.total = test.price * test.number;
	else
		test = Test();

	return is;
}




int main() {


	Test t;
	cin >> t;
	cout << t << endl;

	cout << "t++" << endl ;
	cout << t++ << endl;

	cout << "++t" << endl ;
	cout << ++t << endl;

	cout << "t--" << endl ;
	cout << t-- << endl;

	cout << "--t" << endl ;
	cout << --t << endl;

	cout << endl;
	system("pause");
	return 0;
}


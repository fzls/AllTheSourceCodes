/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 n_sum.cpp
* @version:
* @Time: 		 2015-08-29 10:49:54
* @Description:
*
+----------------------------------------------------------
*/
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
static int count;
void print_decompose(int number);
void rec_print_decompose(string& completed, int lowerbound, int remaining_n, stringstream& iss);



int main() {
	int n;
	cin >> n;
	print_decompose(n);

	cout << endl;
	system("pause");
	return 0;
}
void print_decompose(int number) {
	count = 0;
	string completed;
	stringstream iss;
	iss << number;
	iss >> completed;
	completed += " = ";
	// cout << completed;
	for (int i = 1; i <= number; i++) {
		string completed_ = completed;
		string add;
		iss.clear();
		iss << i;
		iss >> add;
		completed_ = completed_ + " " + add;
		// cout << &completed_ << endl;
		// cout << ++count << " ";
		if (number - i >= i)
			rec_print_decompose(completed_, i, number - i, iss);
		else if (number == i) {
			// if (++count % 4 == 0)
			cout << "No." << ++count << " : " << completed_ <<  endl;
			// else
			// cout << completed_ << " ; ";
		}
		else
			i = number - 1;

	}
}


void rec_print_decompose(string& completed, int lowerbound, int remaining_n, stringstream& iss) {
	for (int i = lowerbound; i <= remaining_n; i++) {
		string completed_ = completed;
		string add;
		iss.clear();
		iss << i;
		iss >> add;
		completed_ = completed_ + " + " + add;
		// cout << &completed_ << endl;
		// cout << ++count << " ";

		if (remaining_n - i >= i)
			rec_print_decompose(completed_, i, remaining_n - i, iss);
		else if (remaining_n == i) {
			// if (++count % 4 == 0)
			cout << "No." << ++count << " : " << completed_ <<  endl;
			// else
			// cout << completed_ << " ; ";
		}
		else
			i = remaining_n - 1;

	}
}

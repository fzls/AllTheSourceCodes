/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 double_number_permutation.cpp
* @version:
* @Time: 		 2015-08-27 16:55:39
* @Description:  Now you are suppose to check if there are more numbers with this property. That is, double a given number with k digits, you are to tell if the resulting number consists of only a permutation of the digits in the original number.
*
+----------------------------------------------------------
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;
string multipy2(const string& original/*, string& doubled*/, int &carry) {
	string doubled(original.size() + 1, '0');
	for (auto i = doubled.size() - 1; i > 0; i--) {
		doubled[i] = (2 * (original[i - 1] - '0') + carry) % 10 + '0' ;
		carry = (2 * (original[i - 1] - '0') + carry) / 10  ;
	}
	doubled[0] = carry + '0' ;
	return doubled;
}
void count(const string& number, std::vector<int> &digit ) {
	for (int i = number.size() - 1; i >= 0; i--) {
		digit[number[i] - '0' ]++;
		// cout << (number[i] - '0') << digit[number[i] - '0' ] << ends;
	}
}
int main() {
	int carry = 0;
	bool permutation = true;
	std::vector<int> digit_ori(10, 0), digit_dou(10, 0) ;

	string original;
	cin >> original;
	// cout << original;
	string doubled(original.size() + 1, '0');
	doubled = multipy2(original/*, doubled*/, carry);

	if (carry == 0) {
		doubled = doubled.substr(1);
		count(original, digit_ori);
		count(doubled, digit_dou);
		for (int i = 0; i < 10; i++) {
			if (digit_ori[i] != digit_dou[i]) {
				permutation = false;
				// cout << i << endl;
				break;
			}
		}
	}
	else
		permutation = false;

	if (permutation)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	// cout << (carry == 0 ? doubled.substr(1) : doubled);
	// if (carry == 0)
	// 	cout << doubled.substr(1);
	// else
	cout << doubled;
	cout << endl;
	// system("pause");

	return 0;
}


/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 polynomial_derivative.cpp
* @version:
* @Time: 		 2015-08-28 09:18:30
* @Description:  02-线性结构2. 一元多项式求导 (25)
*
+----------------------------------------------------------
*/
#include <iostream>
#include <vector>

using namespace std;

class Monomial {
public:
	int coefficient;
	int exponent;
};


int main() {
	std::vector<Monomial> polynomial ;
	Monomial monomial;
	int count_zero = 0;
	while (cin >> monomial.coefficient && cin >> monomial.exponent) {
		if (monomial.coefficient == 0 || monomial.exponent == 0)
			count_zero++;
		polynomial.push_back(monomial);

	}
	int length = polynomial.size() - count_zero;
	for (int i = 0; i < polynomial.size(); i++) {
		if (polynomial[i].coefficient != 0 && polynomial[i].exponent != 0)
			cout << polynomial[i].coefficient *polynomial[i].exponent << " " << polynomial[i].exponent - 1 << (--length == 0 ? "" : " ");
	}
	if (polynomial.size() == count_zero)
		cout << "0 0";


	// cout << endl;
	// system("pause");
	return 0;
}


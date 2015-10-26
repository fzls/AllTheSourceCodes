/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 polynomial_add_and_multipy.cpp
* @version:
* @Time: 		 2015-09-03 08:14:22
* @Description:  02-线性结构1 一元多项式的乘法与加法运算   (20分)
*
+----------------------------------------------------------
*/
#include <iostream>
#include <list>

using namespace std;

struct polynomial
{
	int cofficient;
	int exponent;
};

void add(std::list<polynomial>& poly_1, std::list<polynomial>& poly_2, std::list<polynomial>& sum);
void multipy(std::list<polynomial>& poly_1, std::list<polynomial>& poly_2, std::list<polynomial>& product);
// 3 1 1 3 2 5 3
// 3 1 2 4 3 6 5

int main() {
	int n;
	polynomial temp;
	std::list<polynomial> poly_1, poly_2, product, sum ;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp.cofficient >> temp.exponent;
		poly_1.push_back(temp);
	}


	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp.cofficient >> temp.exponent;
		poly_2.push_back(temp);


	}

	//add
	add(poly_1, poly_2, sum);

	//multipy
	multipy(poly_1, poly_2, product);
	// cout << "----------------start--------------" << endl;
	int j = 0;
	for (auto i = product.begin(); i != product.end(); i++, j++) {
		cout << i->cofficient << " " << i->exponent;
		if (j != product.size() - 1)
			cout << " ";
	}
	if (product.size() == 0)
		cout << "0 0";
	cout << endl;

	j = 0;
	for (auto i = sum.begin(); i != sum.end(); i++, j++) {
		cout << i->cofficient << " " << i->exponent ;
		if (j != sum.size() - 1)
			cout << " ";
	}
	if (sum.size() == 0)
		cout << "0 0";
	cout << endl;

	// cout << endl;
	// system("pause");
	return 0;
}

void add(std::list<polynomial>& poly_1, std::list<polynomial>& poly_2, std::list<polynomial>& sum) {
	sum.clear();
	polynomial temp;
	auto i = poly_1.cbegin();
	auto j = poly_2.cbegin();
	for (; i != poly_1.cend() && j != poly_2.cend();) {
		if (i->exponent > j->exponent) {
			if (i->cofficient != 0) {
				sum.push_back(polynomial(*i));
			}
			++i;
		}
		else if (i->exponent == j->exponent)  {
			if (i->cofficient + j->cofficient != 0) {
				temp.cofficient = i->cofficient + j->cofficient;
				temp.exponent = i->exponent;
				sum.push_back(polynomial(temp));
			}
			++i; ++j;
		}
		else {
			if (j->cofficient != 0) {
				sum.push_back(polynomial(*j));
			}
			++j;
		}
	}
	while (i != poly_1.cend() && i->cofficient != 0) {
		sum.push_back(polynomial(*i));
		++i;
	}
	while (j != poly_2.cend() && j->cofficient != 0) {
		sum.push_back(polynomial(*j));
		++j;
	}
}
void multipy(std::list<polynomial>& poly_1, std::list<polynomial>& poly_2, std::list<polynomial>& product) {
	std::list<polynomial> temp;
	std::list<polynomial> temp_product;
	polynomial poly;

	for (auto i = poly_1.cbegin(); i != poly_1.cend(); i++) {
		for (auto j = poly_2.cbegin(); j != poly_2.cend(); j++) {
			poly.cofficient = i->cofficient * j->cofficient;
			poly.exponent = i->exponent + j->exponent;
			temp.push_back(polynomial(poly));
		}
		temp_product = product;
		// cout << endl << "-----------temp_product------------" << endl;
		// for (auto k : temp_product)
		// 	cout << k.cofficient << " " << k.exponent << ends;

		// cout << endl << "-----------temp------------" << endl;
		// for (auto k : temp)
		// 	cout << k.cofficient << " " << k.exponent << ends;

		add(temp_product, temp, product);
		// cout << endl << "------------product------------" << endl;
		// for (auto k : product)
		// 	cout << k.cofficient << " " << k.exponent << ends;
		// system("pause");
		temp.clear();
	}
}

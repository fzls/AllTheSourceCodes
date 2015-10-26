/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 MyComplex.cpp
* @version:
* @Time: 		 2015-08-15 12:30:48
* @Description:
*
+----------------------------------------------------------
*/
#include <iostream>
#include "MyComplex.h"
using namespace std;
MyComplex::MyComplex() {
	re = 0;
	im = 0;
}
MyComplex::MyComplex(double re, double im) {
	this->re = re;
	this->im = im;
}
MyComplex MyComplex::operator+(const MyComplex& SecondComplex) {
	MyComplex sum;
	sum.re = this->re + SecondComplex.re;
	sum.im = this->im + SecondComplex.im;
	return sum;
}

MyComplex& MyComplex::operator-(const MyComplex& SecondComplex) {
	MyComplex difference;
	difference.re = this->re - SecondComplex.re;
	difference.im = this->im - SecondComplex.im;
	return difference;
}

MyComplex& MyComplex::operator*(const MyComplex& SecondComplex) {
	MyComplex product;
	product.re = this->re * SecondComplex.re - this->im * SecondComplex.im;
	product.im = this->im * SecondComplex.re + this->re * SecondComplex.im;
	return product;
}

MyComplex& MyComplex::operator/(const MyComplex& SecondComplex) {
	MyComplex quotient;
	quotient.re = (this->re * SecondComplex.re + this->im * SecondComplex.im) / (SecondComplex.re * SecondComplex.re + SecondComplex.im * SecondComplex.im);
	quotient.im = (this->im * SecondComplex.re - this->re * SecondComplex.im) / (SecondComplex.re * SecondComplex.re + SecondComplex.im * SecondComplex.im);
	return quotient;
}

double& MyComplex::operator[](const int& index) {
	if (index == 0) {
		return this->re;
	}
	else if (index == 1) {
		return this->im;
	}
	else {
		cout << "subscript out of bound ";
		return -1.0;
	}
}

bool MyComplex::operator==(const MyComplex& SecondComplex) {
	return (this->re == SecondComplex.re && this->im == SecondComplex.im);
}

bool MyComplex::operator!=(const MyComplex& SecondComplex) {
	// return !(this->re==SecondComplex.re&&this->im==SecondComplex.im);
	return !(*this == SecondComplex);
}

ostream& MyComplex::operator<<(ostream& stream, MyComplex& mycomplex) {
	stream << "(" << mycomplex.re;
	if (MyComplex.im >= 0) {
		stream << "+" << MyComplex.im << "i" << ")" ;
	}
	else {
		stream << MyComplex.im << "i" << ")" ;
	}
	return stream;
}
istream& MyComplex::operator>>(istream& stream, MyComplex& mycomplex) {
	stream >> mycomplex.re;
	stream >> mycomplex.im;
	return stream;
}

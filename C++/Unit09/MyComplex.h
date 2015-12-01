/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 MyComplex.h
* @version:
* @Time: 		 2015-08-15 12:22:54
* @Description:
*
+----------------------------------------------------------
*/
// #pragma once
#include <iostream>
using namespace std;
class MyComplex {
private:
	double re, im;
public:
	MyComplex();
	MyComplex(double re, double im);
	MyComplex& operator+(const MyComplex& SecondComplex);
	MyComplex& operator-(const MyComplex& SecondComplex);
	MyComplex& operator*(const MyComplex& SecondComplex);
	MyComplex& operator/(const MyComplex& SecondComplex);
	double& operator[](const int& index);
	bool operator==(const MyComplex& SecondComplex);
	bool operator!=(const MyComplex& SecondComplex);
	friend ostream &operator<<(ostream& stream, MyComplex& mycomplex);
	friend istream &operator>>(istream& stream, MyComplex& mycomplex);

};


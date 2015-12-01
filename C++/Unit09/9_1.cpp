/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 9_1.cpp
* @version:
* @Time: 		 2015-08-15 11:42:19
* @Description:  题目内容：
1. 关于复数：
复数x被定义为二元有序实数对(a,b)，记为z=a+bi,这里a和b是实数，i是虚数单位。在复数a+bi中，a=Re(z)称为实部，b=Im(z)称为虚部。当虚部等于零时，这个复数可以视为实数；当z的虚部不等于零时，实部等于零时，常称z为纯虚数。
复数的四则运算规定为：
   加法法则：(a+bi)+(c+di)=(a+c)+(b+d)i；
   减法法则：(a+bi)－(c+di)=(a－c)+(b－d)i；
   乘法法则：(a+bi)·(c+di)=(ac－bd)+(bc+ad)i；
   除法法则：(a+bi)÷(c+di)=[(ac+bd)/(c²+d²)]+[(bc-ad)/(c²+d²)]i.

2. 创建一个类 MyComplex，用来表示复数。
3. 重载流提取运算符 >> ，使之可以读入以下格式的输入(两个数值之间使用空白分隔)，将第一个数值存为复数的实部，将第二个数值存为复数的虚部：
   -1.1  2.0
   +0   -4.5
4. 重载流插入运算符 << ，使之可以将复数输出为如下的格式(实部如果是非负数，则不输出符号位；输出时要包含半角左右小括号)：
  (-1.1+2.0i)
  (0-4.5i)
5. 不可以改动主函数内部的任何表达式或者语句

*
+----------------------------------------------------------
*/
#include <iostream>
#include <cstdlib>
#include <limits>
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
MyComplex& MyComplex::operator+(const MyComplex& SecondComplex) {
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

MyComplex& MyComplex::operator *(const MyComplex& SecondComplex) {
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
		return this->im;
	}
}

bool MyComplex::operator==(const MyComplex& SecondComplex) {
	return (this->re == SecondComplex.re && this->im == SecondComplex.im);
}

bool MyComplex::operator!=(const MyComplex& SecondComplex) {
	// return !(this->re==SecondComplex.re&&this->im==SecondComplex.im);
	return !(*this == SecondComplex);
}

ostream& operator<<(ostream& stream, MyComplex& mycomplex) {
	stream << "(" << mycomplex.re;
	if (mycomplex.im >= 0) {
		stream << "+" << mycomplex.im << "i" << ")" ;
	}
	else {
		stream << mycomplex.im << "i" << ")" ;
	}
	return stream;
}
istream& operator>>(istream& stream, MyComplex& mycomplex) {
	stream >> mycomplex.re;
	stream >> mycomplex.im;
	return stream;
}



int main() {
	MyComplex z1, z2;
	cin >> z1;
	cin >> z2;
	cout << z1 << " " << z2 << endl;  //z1和z2之间间隔1个空格
	cout << (z1 + z2) << " " << (z1 - z2) << endl; //z1和z2之间间隔1个空格
	cout << (z1 * z2) << " " << (z1 / z2) << endl; //z1和z2之间间隔1个空格
	cout << (z1 == z2) << " " << (z1 != z2) << endl; //z1和z2之间间隔1个空格

	// GCC及VC编译器在调试模式下会暂停，便于查看运行结果
#if ( defined(__DEBUG__) || defined(_DEBUG) )
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
#endif

	cout << endl;
	system("pause");
	return 0;
}


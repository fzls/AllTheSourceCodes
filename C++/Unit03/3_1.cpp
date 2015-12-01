/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 3.1.cpp
* @version:
* @Time: 		 2015-08-09 19:17:03
* @Description:  1本题要求实现两个重载的swap函数，每个swap函数都可交换3个整数a，b，c的值。将a的值存入b，b的值存入c，c的值存入a， 并且返回三个整数中最大的数的值。例如a,b,c的值为1,2,3，则交换后，a,b,c的值为3,1,2，所返回的值为3。（10分）
题目内容：
在主函数中一次读入三个整数的值存入a、b、c中；
以a、b、c作为实参，先后连续调用两个swap函数；
最后输出a、b、c三个整数中最大的值，以及三个整数；
变量定义时均应赋初值0。
不得使用C语言中的输入输出函数

函数接口定义：
int swap ( int& x, int& y, int& z);  //三个参数均为引用类型
int swap ( int* x, int* y, int* z); //三个参数均为指针类型
swap()在交换三个整数的值后，返回x,y,z中最大的数的值

输入格式:
空格分隔的三个整数
整数1 整数2 整数3

输出格式：
空格分隔的四个整数
最大数 a的值 b的值 c的值

输入样例：
1 2 3

输出样例：
3 2 3 1
时间限制：500ms内存限制：32000kb
*
+----------------------------------------------------------
*/
#include <iostream>
using namespace std;
int swap( int& x, int& y, int& z);  //三个参数均为引用类型
int swap( int* x, int* y, int* z); //三个参数均为指针类型
int main() {
	int x = 0, y = 0, z = 0, max = 0;
	cin >> x >> y >> z;
	max = swap(x, y, z);
	max = swap(&x, & y, &z);
	cout << max << " " << x << " " << y << " " << z << " " << endl;
	printf("\n");
	system("pause");
	return 0;
}
int swap ( int& x, int& y, int& z) { //三个参数均为引用类型
	int temp, max;
	temp = x;
	x = z;
	z = y;
	y = temp;
	max = x > y ? x > z ? x : z : y > z ? y : z;
	return max;
}
int swap ( int* x, int* y, int* z) { //三个参数均为指针类型
	int temp, max;
	temp = *x;
	*x = *z;
	*z = *y;
	*y = temp;
	max = *x > *y ? *x > *z ? *x : *z : *y > *z ? *y : *z;
	return max;

}

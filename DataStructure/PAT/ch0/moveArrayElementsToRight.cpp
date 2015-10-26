/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 moveArrayElementsToRight.cpp
* @version:
* @Time: 		 2015-08-27 15:58:26
* @Description:  数组元素循环右移问题
*一个数组A中存有N（N>0）个整数，在不允许使用另外数组的前提下，将每个整数循环向右移M（M>
*=0）个位置，即将A中的数据由（A0 A1……AN-1）变换为（AN-M …… AN-1 A0 A1……AN-M-
*1）（最后M个数循环移至最前面的M个位置）。如果需要考虑程序移动数据的次数尽量少，要如何设计移动的方法？
*输入格式：每个输入包含一个测试用例，第1行输入N ( 1<=N<=100)、M（M>=0）；第2行输入N个整数，之间用空格分隔。
*输出格式：在一行中输出循环右移M位以后的整数序列，之间用空格分隔，序列结尾不能有多余空格。
*
*
*
*
+----------------------------------------------------------
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
	std::vector<int> array ;

	int n, m, element;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> element;
		array.push_back(element);
	}
	m %= n;
	array.reserve(m + n);
	for (int i = n - 1; i >= 0; i--)
		array[i + m] = array[i];
	for (int i = 0; i < m; i++)
		array[i] = array[i + n];
	for (int i = 0; i < n; i++)
		cout << array[i] << (i == n - 1 ? "" : " ");

	// cout << endl;
	// system("pause");
	return 0;
}


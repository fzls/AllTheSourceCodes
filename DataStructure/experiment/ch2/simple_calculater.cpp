/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 simple_calculater.cpp
* @version:
* @Time: 		 2015-08-29 09:48:14
* @Description:
*
+----------------------------------------------------------
*/
#include <iostream>

using namespace std;

int main() {
	int operand1, operand2;
	char operators;
	bool is_zero_divided = false, is_illegal_input = false;
	cin >> operand1 >> operators;
	while (operators != '=') {
		cin >> operand2;
		switch (operators) {
		case '+' : operand1 += operand2 ; break;
		case '-' : operand1 -= operand2 ; break;
		case '*' : operand1 *= operand2 ; break;
		case '/' :
			if (operand2 == 0) {
				is_zero_divided = true;
			}
			else
				operand1 /= operand2 ;
			break;
		default: is_illegal_input = true; break;

		}
		if (is_zero_divided || is_illegal_input)
			break;
		cin >> operators;
	}
	if (is_zero_divided)
		cout << "除法分母为零！" << endl;
	else if (is_illegal_input)
		cout << "非法输入！" << endl;
	else
		cout << operand1 << endl;
	cout << endl;
	system("pause");
	return 0;
}


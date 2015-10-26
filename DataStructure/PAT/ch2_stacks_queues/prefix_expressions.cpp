/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 prefix_expressions.cpp
* @version:
* @Time: 		 2015-08-28 09:55:16
* @Description: this version tried to read the operator and operand directly and failed to figure whether the next input is which.
*
+----------------------------------------------------------
*/
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
union OP {
	char otor;
	double number;
};
class Stack {
public:
	Stack() {
		pool.reserve(capacity);
	}
	void push(OP ch) {
		pool.push_back(ch);
	}
	bool is_empty() {
		return pool.size() == 0;
	}
	OP pop() {
		OP top = pool.back();
		pool.pop_back();
		return top;
	}
	OP get_top() {
		return pool.back();
	}
	int get_size() {
		return pool.size();
	}

private:
	std::vector<OP> pool ;
	int capacity = 30;

};



int main() {
	Stack stack;
	char  Operator;
	OP op;
	bool is_error = false;
	double operand1, operand2;
	while (cin >> op) {
		if (stack.is_empty() || op == '+' || op == '-' || op == '*' || op == '/') //if empty
			stack.push(op);
		//if stack top is number and op is number
		// else if (stack.get_top() - '0' >= 0 && stack.get_top() - '0' <= 9) {
		else {
			operand1 = op;
			while (!(stack.get_top() == '+' || stack.get_top() == '-' || stack.get_top() == '*' || stack.get_top() == '/')) {
				operand2 = stack.pop();
				Operator = stack.pop();
				if (Operator == '+' || Operator == '-' || Operator == '*' || Operator == '/') {
					switch (Operator) {
					case '+': operand2 += operand1; break;
					case '-': operand2 -= operand1; break;
					case '*': operand2 *= operand1; break;
					case '/': operand2 /= operand1; break;
					}
					operand1 = operand2;
				}
				else {//if not Operator
					is_error = true;
					break;
				}
			}
			stack.push(operand1);
			if (is_error)
				break;
		}
	}
	if (stack.get_size() != 1)
		is_error = true;
	if (is_error)
		cout << "ERROR";
	else
		cout << fixed << setprecision(1) << operand1;


	cout << endl;
	system("pause");
	return 0;
}


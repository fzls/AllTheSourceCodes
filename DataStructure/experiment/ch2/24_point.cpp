/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 24_point.cpp
* @version:
* @Time: 		 2015-08-30 09:58:02
* @Description:
*
+----------------------------------------------------------
*/
#include <iostream>
#include <vector>
const int OPERAND_NUMBERS = 4;
const int OPERATOR_NUMBERS = 4;
using namespace std;

void operators_initialize(vector<char>& operators);
void operators_per_initialize(vector<vector<char>>& operators_per, vector<char>& operators);

void input_number_initialize(vector<int>& input_number);
void operands_per_initialize(vector<vector<int>>& operands_per, vector<int>& input_number);

bool check(vector<int>& operands, vector<char>& operators);

int compute(int operands1, int operands2, char operators);

int main() {
	vector<int> input_number ;
	vector<char> operators ;
	vector<vector<int>> operands_per ;
	vector<vector<char>> operators_per ;
	bool found = false;
	input_number_initialize(input_number);
	operators_initialize(operators)	;
	operands_per_initialize(operands_per, input_number);
	operators_per_initialize(operators_per, operators);
	for (auto i : operands_per) {
		for (auto j : operators_per)
			if (check(i, j)) {
				found = true;
				break;
			}
		if (found)
			break;
	}
	if (!found)
		cout << "-1";

	cout << endl;
	system("pause");
	return 0;
}

void input_number_initialize(vector<int>& input_number) {
	int number;
	for (int i = 0; i < OPERAND_NUMBERS; i++) {
		cin >> number;
		input_number.push_back(number);
	}
}

void operands_per_initialize(vector<vector<int>>& operands_per, vector<int>& input_number) {
	for (int i = 0; i < OPERAND_NUMBERS; i++)
		for (int j = 0; j < OPERAND_NUMBERS; j++)
			for (int k = 0; k < OPERAND_NUMBERS; k++)
				for (int l = 0; l < OPERAND_NUMBERS; l++)
					if (i != j && i != k && i != l && j != k && j != l && k != l) {
						vector<int> temp ;
						temp.push_back(input_number[i]);
						temp.push_back(input_number[j]);
						temp.push_back(input_number[k]);
						temp.push_back(input_number[l]);
						operands_per.push_back(temp);
					}
}

void operators_initialize(vector<char>& operators) {
	operators.push_back('+');
	operators.push_back('-');
	operators.push_back('*');
	operators.push_back('/');
}

void operators_per_initialize(vector<vector<char>>& operators_per, vector<char>& operators) {
	for (int i = 0; i < OPERATOR_NUMBERS; i++)
		for (int j = 0; j < OPERATOR_NUMBERS; j++)
			for (int k = 0; k < OPERATOR_NUMBERS; k++) {
				vector<char> temp ;
				temp.push_back(operators[i]);
				temp.push_back(operators[j]);
				temp.push_back(operators[k]);
				operators_per.push_back(temp);
			}
}



bool check(vector<int>& operands, vector<char>& operators) {
	bool found = false;
	if (compute(compute(compute(operands[0], operands[1], operators[0]), operands[2], operators[1]), operands[3], operators[2]) == 24) {
		found = true;
		cout << "((" << operands[0]  << operators[0]  << operands[1] << ")"  << operators[1]  << operands[2] << ")"  << operators[2]  << operands[3] << endl;
	}
	else if (compute(compute(operands[0], operands[1], operators[0]), compute(operands[2], operands[3], operators[2]), operators[1]) == 24) {
		found = true;
		cout << "(" << operands[0]  << operators[0]  << operands[1] << ")"  << operators[1] << "(" << operands[2]   << operators[2]  << operands[3] << ")" << endl;
	}
	else if (compute(compute(operands[0], compute(operands[1], operands[2], operators[1]), operators[0]), operands[3], operators[2]) == 24) {
		found = true;
		cout << "(" << operands[0]  << operators[0] << "(" << operands[1]   << operators[1]  << operands[2] << "))"  << operators[2]  << operands[3] << endl;
	}
	else if (compute(operands[0] , compute(compute(operands[1], operands[2], operators[1]), operands[3], operators[2]), operators[0]) == 24) {
		found = true;
		cout  << operands[0]  << operators[0] << "((" << operands[1]   << operators[1]  << operands[2] << ")"  << operators[2]  << operands[3] << ")" << endl;
	}
	else if (compute(operands[0] , compute(operands[1] , compute(operands[2], operands[3], operators[2]), operators[1]), operators[0]) == 24) {
		found = true;
		cout  << operands[0]  << operators[0] << "(" << operands[1]   << operators[1] << "(" << operands[2]   << operators[2]  << operands[3] << "))" << endl;
	}


	return found;
}
int compute(int operands1, int operands2, char operators) {
	int result;
	switch (operators) {
	case '+' : result = operands1 + operands2 ; break;
	case '-' : result = operands1 - operands2 ; break;
	case '*' : result = operands1 * operands2 ; break;
	case '/' :
		if (operands2 != 0 && operands1 % operands2 == 0 )
			result = operands1 / operands2 ;
		else
			result = 100000;
		break;
	}
	return result;
}

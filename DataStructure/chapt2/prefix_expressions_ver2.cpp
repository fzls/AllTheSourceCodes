/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 prefix_expressions_ver2.cpp
* @version:
* @Time: 		 2015-08-28 11:30:15
* @Description:  this version use string to store the input , and then deal with it, then use the stack
* to solve the problem/
*
+----------------------------------------------------------
*/
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <vector>
#include <iomanip>

using namespace std;

bool is_digit(char ch);//find out whether this character is a number

int main() {
	stack<double, std::vector<double>> num_stack ;//make stack with container vector
	string line;//to get a line of expresion
	double operand1, operand2;
	bool is_error = false;//indicate whether a error had happened
	istringstream words;//to convert substring into double

	getline(cin, line);

	auto index1 = line.size() - 1;//the end of the last substring
	auto index2 = index1;
	index2 = line.rfind(" ", index1);// one unit before the start position of the substring

	for (int i = static_cast<int>(line.size() - 1) ; i >= 0;) {
		if (is_digit(line[i])) {//if this char is a number , then it means this substring should be a number,else it should be an operator
			string word;
			if (index2 != string::npos)//if this is the first substring , then we should handle it in a different way
				word = line.substr(index2 + 1, index1 - index2); //the first parameter is the start position, and the second is the number of characters to include in substring
			else
				word = line.substr(0, index1);//the first substring case
			words.clear();//reset the eofbit,if not reset, subsequent input would be invalid
			// test for what if not reset the state of the stringstream
			// cout << "EOF " << words.eof() << endl;
			// cout << "GOOD " << words.good() << endl;
			// cout << "FAIL " << words.fail() << endl;
			// cout << "BAD " << words.bad() << endl;
			// cout << "-------------------------" << endl;
			words.str(word);
			words >> operand1;//convert the substring into double and then push it into the stack
			num_stack.push(operand1);
			// cout << num_stack.top() << endl << endl; //
		}
		else {//if it is an operator , then pop two data off the stack and push the result into the stack
			operand1 = num_stack.top(); num_stack.pop();
			operand2 = num_stack.top(); num_stack.pop();
			switch (line[i]) {//decide which arithmetic operation to use
			case '+': operand1 += operand2; break;
			case '-': operand1 -= operand2; break;
			case '*': operand1 *= operand2; break;
			case '/':
				if (operand2 >= 1e-6 || operand2 <= -1e-6)//check if zero divided
					operand1 /= operand2;
				else {
					is_error = true;
					break;
				}
				break;
			}
			num_stack.push(operand1);//push the result into the stack
		}
		if (index2 == string::npos) {//if it is the first substring(namely the last string we handle, cause we handle it backwards)
			break;
		}
		index1 = index2 - 1;//because there is only one blank space between two substring, so index2-1 is the end of the next substring we want, if there is more than one blank space, then we can use index1= line.find_last_not_of(" ");
		index2 = line.rfind(" ", index1);
		i = static_cast<int>(index1) ;
	}
	if (num_stack.size() != 1)//if evething is fine, then finally there should be only one element in the stack , namely the final result
		is_error = true;

	if (!is_error)
		cout << fixed << setprecision(1) << num_stack.top();
	else
		cout << "ERROR";

	// cout << endl;
	system("pause");
	return 0;
}

bool is_digit(char ch) {
	return ch >= '0' && ch <= '9';
}

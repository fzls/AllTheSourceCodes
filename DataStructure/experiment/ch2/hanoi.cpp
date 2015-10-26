/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 hanoi.cpp
* @version:
* @Time: 		 2015-08-30 14:46:58
* @Description:  stack version
*
+----------------------------------------------------------
*/
#include <iostream>
#include <stack>
#include <vector>
#include <ctime>

using namespace std;

struct Hanoi
{
	int numbers;
	char start;
	char transfer;
	char destination;
	Hanoi(int n = 0, char s = 'a', char t = 'b' , char d = 'c' ): numbers(n), start(s), transfer(t), destination(d) {}
};

void solve_hanoi(int numbers);

void recursive_hanoi(int n, char start, char transfer, char destination);

int main() {
	clock_t time1;
	clock_t time2;
	int n;
	cin >> n;

	time1 = clock();
	solve_hanoi(n);
	time1 = clock() - time1;


	time2 = clock();
	recursive_hanoi(n, 'a', 'b', 'c');
	time2 = clock() - time2;
	cout << "----------------------------------" << endl;
	cout << "solve_hanoi(n) : Clicks: " << time1 << "    " << ((float)time1) / CLOCKS_PER_SEC << " seconds" << endl;
	cout << "recursive_hanoi(n) : Clicks: " << time2 << "    " << ((float)time2) / CLOCKS_PER_SEC << " seconds" << endl;



	cout << endl;
	system("pause");
	return 0;
}
void solve_hanoi(int numbers) {
	stack<Hanoi, std::vector<Hanoi>> hanoi_stack;
	Hanoi hanoi(numbers, 'a', 'b', 'c');
	hanoi_stack.push(hanoi);
	while (!hanoi_stack.empty()) {
		Hanoi hanoi = hanoi_stack.top();
		hanoi_stack.pop();
		if (hanoi.numbers == 1) {
			cout << hanoi.start << " -> " << hanoi.destination << endl;
		}
		else {
			Hanoi temp;
			temp = {hanoi.numbers - 1, hanoi.transfer, hanoi.start, hanoi.destination};
			hanoi_stack.push(temp);

			temp = {1 , hanoi.start, hanoi.transfer , hanoi.destination};
			hanoi_stack.push(temp);

			temp = {hanoi.numbers - 1, hanoi.start, hanoi.destination, hanoi.transfer};
			hanoi_stack.push(temp);

		}

	}
}

void recursive_hanoi(int n, char start, char transfer, char destination) {
	if (n == 1)
		cout << start << " -> " << destination << endl;
	else {
		recursive_hanoi(n - 1, start, destination, transfer);
		recursive_hanoi(1, start, transfer, destination);
		recursive_hanoi(n - 1, transfer, start, destination);
	}
}

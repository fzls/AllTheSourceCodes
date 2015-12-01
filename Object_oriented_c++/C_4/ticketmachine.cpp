/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 ticketmachine.cpp
* @version:	 	 v1.0
* @Time: 		 2015-07-25 18:59:21   Finished 2015-07-29 15:03:16
* @Description:  construct a ticket machine.  可以继续去添加功能 = =
*
+----------------------------------------------------------
*/
#include <iostream>
#include "TicketMachine.h"
using namespace std;

TicketMachine::TicketMachine(): PRICE(10) {
	balance = 0;
	total = 0;
}

TicketMachine::~TicketMachine() {

}

void TicketMachine::showPrompt() {
	cout << "something";
}

void TicketMachine::insertMoney(int money) {
	balance += money;
}

void TicketMachine::showBalance() {
	cout << "Your balance is " << balance << endl;
}

// void TicketMachine::initBalance(int Balance) {
// 	balance += Balance;
// }

void TicketMachine::buyThings(int number) {
	total += PRICE * number;
	while (total > balance) {
		cout << "sorry, you don't have enough balance, please insert more money" << endl;
		int money; cin >> money;
		insertMoney(money);
	}
}

void TicketMachine::showTotal() {
	cout << "the total cost is " << total << endl;
}

void TicketMachine::changeBalance() {
	balance -= total;
}

int main() {
	TicketMachine tm;
	tm.showBalance();
	cout << "please insert money" << endl;
	int money; cin >> money;
	tm.insertMoney(money);
	// tm.initBalance(money);
	tm.showBalance();
	cout << "please choose how many stuff do you like to buy" << endl;
	int number; cin >> number;
	tm.buyThings(number);
	tm.showTotal();
	tm.changeBalance();
	tm.showBalance();

	printf("\n");
	system("pause");
	return 0;
}


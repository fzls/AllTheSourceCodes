/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 TicketMachine.h
* @version:	 	 v.10
* @Time: 		 2015-07-25 19:20:35
* @Description:
*
+----------------------------------------------------------
*/
#ifndef TicketMachine_H_
#define TicketMachine_H_

class TicketMachine {
public:
	TicketMachine();
	virtual ~TicketMachine();
	void showPrompt();
	void insertMoney(int money);
	void showBalance();
	void printTicket();
	void showTotal();
	// void initBalance(int Balance);
	void buyThings(int number);
	void changeBalance();
private:
	const int PRICE;
	int balance;
	int total;
};

#endif

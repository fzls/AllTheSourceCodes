#pragma once
#include <string>
#include <iostream>
using namespace std;



class Sales_data
{
	friend Sales_data  add(const Sales_data&, const Sales_data&);
	friend istream& read(istream&, Sales_data&);
	friend ostream& print(ostream&, const Sales_data&);


public:
	/*=============================================================
	=            delegating version of constructors               =
	=============================================================*/
	Sales_data(const std::string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p * n) {}

	Sales_data(): Sales_data("", 0, 0) {}
	Sales_data(const std::string &s): Sales_data(s, 0, 0) {}
	Sales_data(std::istream &is): Sales_data() {
		read(is, *this);
	}

	/*=====  End of delegating version of constructors     ======*/


	// Sales_data() = default;
	// Sales_data(const std::string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p * n) {}
	// Sales_data(const std::string &s): bookNo(s) {}
	// Sales_data(std::istream&);
	string isbn() const {return bookNo;}
	Sales_data& combine(const Sales_data&);
	~Sales_data();
private:
	double avg_price()const {return units_sold ? revenue / units_sold : 0;}
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
Sales_data  add(const Sales_data&, const Sales_data&);
istream& read(istream&, Sales_data&);
ostream& print(ostream&, const Sales_data&);

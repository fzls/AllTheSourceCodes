#include "gerneral_interface.h"
#include <string>
#include <cctype>

const std::string month="01 02 03 04 05 06 07 08 09 10 11 12";
const std::string day="01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 "\
					"16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31";

bool isNum(const std::string& paswrd)
{
	bool flag=1;
	for(int i=0;i<paswrd.length();++i)
	{
		if(!isdigit(paswrd[i]))
		{
			flag=0;
			break;
		}
	}
	
	return flag;
}

bool isPureAlpha(const std::string paswrd)
{
	bool flag=1;
	for(int i=0;i<paswrd.length();++i)
	{
		if(!isalpha(paswrd[i]))
		{
			flag=0;
			break;
		}
	}
	
	return flag;	
}

bool isBirthday(const std::string& paswrd)
{
	bool judge=0;
	switch(paswrd.size())
	{
		case 6:
			if(month.find(paswrd.c_str(),2,2)&&
							month.find(paswrd.c_str(),4,2))
			{
				judge=1;
			}
			break;
		case 8:
			if(month.find(paswrd.c_str(),4,2)&&
							month.find(paswrd.c_str(),6,2))
			{
				judge=1;
			}
			break;
		default :
			judge=0;
			break;
	}
	return judge;
}

bool hasSpecialCharacter(const std::string& paswrd)
{
	bool flag=0;
	for(int i=0;i<paswrd.size();++i)
	{
		if(!isalnum(paswrd[i]))
		{
			flag=1;
			break;
		}
	}
}


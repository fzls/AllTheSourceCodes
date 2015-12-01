#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cctype>
#include "load.h"
#include "gerneral_interface.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	std::string passwordSet;
	passwordLoad(passwordSet);
	
	int pureNumPaswrdCnt=0;
	int totalLength=0;
	int birthdayPaswrdCnt=0;
	int pureAlphaPaswrdCnt=0;
	int totalPaswrdCnt=0;
	int hasSpecialCharacterCnt=0;
	
	std::string word;
	std::istringstream instr(passwordSet);
	
	while(instr>>word)
	{
		totalPaswrdCnt++;
		if(isNum(word))
		{
			pureNumPaswrdCnt++;
			totalLength+=word.length();
			if(isBirthday(word))
			{
				birthdayPaswrdCnt++;
			}
		}
		else if(isPureAlpha(word))
		{
			pureAlphaPaswrdCnt++;
		}
		else if(hasSpecialCharacter(word))
		{
			hasSpecialCharacterCnt++;
		}
	}
	
	std::cout<<"纯数字密码的个数："<<pureNumPaswrdCnt<<std::endl;
	std::cout<<"纯数字密码的平均长度："<<std::setprecision(3)<<(double)totalLength/pureNumPaswrdCnt<<std::endl; 
	std::cout<<"以生日或类似生日为密码的个数："<<birthdayPaswrdCnt<<std::endl;
	std::cout<<"纯字母密码的个数："<<pureAlphaPaswrdCnt<<std::endl;
	std::cout<<"含有特殊字符的密码个数："<<hasSpecialCharacterCnt<<std::endl;
	std::cout<<"含有数字&字符的密码的个数："<<totalPaswrdCnt-pureNumPaswrdCnt-
											      pureAlphaPaswrdCnt-hasSpecialCharacterCnt<<std::endl;
	return 0;
}





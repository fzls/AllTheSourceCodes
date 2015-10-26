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
	
	std::cout<<"����������ĸ�����"<<pureNumPaswrdCnt<<std::endl;
	std::cout<<"�����������ƽ�����ȣ�"<<std::setprecision(3)<<(double)totalLength/pureNumPaswrdCnt<<std::endl; 
	std::cout<<"�����ջ���������Ϊ����ĸ�����"<<birthdayPaswrdCnt<<std::endl;
	std::cout<<"����ĸ����ĸ�����"<<pureAlphaPaswrdCnt<<std::endl;
	std::cout<<"���������ַ������������"<<hasSpecialCharacterCnt<<std::endl;
	std::cout<<"��������&�ַ�������ĸ�����"<<totalPaswrdCnt-pureNumPaswrdCnt-
											      pureAlphaPaswrdCnt-hasSpecialCharacterCnt<<std::endl;
	return 0;
}





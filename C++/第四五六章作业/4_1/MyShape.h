#pragma once
#include <iostream>
using namespace std;
#include<string>
class MyShape{
	public:
		MyShape(); 
		void setColor(int R,int G,int B);
		int getR() const;
		int getG() const;
		int getB() const;
		virtual void Draw() = 0;
	
	
	
	private:
		int R,G,B;
		string enter;
		string leave;
};

#pragma once 
#include <iostream>
using namespace std;
class Screen {
public:
//	Screen(int width, int height);
	~Screen();
//	Screen(const Screen& screen);
	void setScreen(int width, int height);
	int getWidth()const ;
	int getHeight()const ;
	static Screen* getInstance(int width=640,int height=480);
	static void deleteInstance();
private:
	Screen();
	Screen(int width, int height);
	static int width;
	static int height;
	string enter;
	string leave;
	static Screen* instance;
};



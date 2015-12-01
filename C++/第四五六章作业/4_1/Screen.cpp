#include "Screen.h"
#include <iostream>
#include <cstdlib>
#include <graphics.h>
using namespace std;

int Screen::width = 640;
int Screen::height = 480;
static Screen* instance;
Screen::Screen(const Screen& screen){
	this->enter=screen.enter;
	this->leave=screen.leave;
//	this->instance=screen.instance;
//	static int width;
//	static int height;
//	string enter;
//	string leave;
//	static Screen* instance;
}

 Screen* Screen::getInstance(int width,int height){
// 	static Screen* instance;
	if(instance==0){
		if (width > 1000 || height > 1000) {
		cout << "invalid screen size" << endl;

		exit(-1);
	}
		Screen::instance = new Screen(width,height);
//		instance->setScreen(width,height);
	}
	return instance;
}
void Screen::deleteInstance(){
	delete instance;
}


Screen::Screen() {
	this->width = 640;
	this->height = 480;
	this->enter="enter screen";
	this->leave="leave screen";
	initgraph(width,height);
//	outtextxy(10,10,"screen");
	cout << enter << endl;
}

Screen::Screen(int width, int height) {
//	if (width > 1000 || height > 1000) {
//		cout << "invalid screen size" << endl;
//
//		exit(-1);
//	}
	this->width = width;
	this->height = height;
	this->enter="enter screen";
	this->leave="leave screen";
	initgraph(width,height);
//	outtextxy(10,10,"screen");
	cout << enter << endl;
}

Screen::~Screen(){
	closegraph();
	cout<<leave<<endl;
}
void Screen::setScreen(int width, int height) {
	if (width > 1000 || height > 1000) {
//		outtextxy(width/2,height/2,"invalid screen size");
		cout << "invalid screen size" << endl;
		system("pause");

		exit(-1);
	}
	this->width = width;
	this->height = height;
//	outtextxy(20,20,"screen");
//	cout << "screen" << endl;
}

int Screen::getWidth() const {
	return width;
}

int Screen::getHeight() const {
	return height;
}


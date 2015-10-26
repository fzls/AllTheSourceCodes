#include "Screen.h"
#include <iostream>
#include <cstdlib>
#include <graphics.h>
using namespace std;

Screen::Screen() {
	this->width = 640;
	this->height = 480;
	
	initgraph(width,height);
	outtextxy(10,10,"screen");
//	cout << "screen" << endl;
}

Screen::Screen(int width, int height) {
	if (width > 1000 || height > 1000) {
		cout << "invalid screen size" << endl;

		exit(-1);
	}
	this->width = width;
	this->height = height;
	initgraph(width,height);
	outtextxy(10,10,"screen");
//	cout << "screen" << endl;
}
Screen::~Screen(){
	closegraph();
}
void Screen::setScreen(int width, int height) {
	if (width > 1000 || height > 1000) {
		outtextxy(width/2,height/2,"invalid screen size");
//		cout << "invalid screen size" << endl;
		system("pause");

		exit(-1);
	}
	this->width = width;
	this->height = height;
	outtextxy(20,20,"screen");
//	cout << "screen" << endl;
}

int Screen::getWidth() const {
	return width;
}

int Screen::getHeight() const {
	return height;
}


#include <iostream>
#include "Screen.h"
#include "MyCircle.h"
#include <graphics.h>
using namespace std;
//Screen* Screen::instance;
void MyCircle::setColor(int R,int G,int B){
	this->R=R;
	this->G=G;
	this->B=B;
}

MyCircle::MyCircle(){
	this->x=200;
	this->y=200;
	this->r=100;
	this->R=255;
	this->G=255;
	this->B=255;
	cout<<"mycircle"<<endl;
}

MyCircle::MyCircle(int x,int y,int r){
	this->x=x;
	this->y=y;
	this->r=r;
	this->R=255;
	this->G=255;
	this->B=255;
	cout<<"mycircle"<<endl;
}

MyCircle::MyCircle(const MyCircle& mycircle){
	this->x=mycircle.x;
	this->y=mycircle.y;
	this->r=mycircle.r;
	this->R=mycircle.R;
	this->G=mycircle.G;
	this->B=mycircle.B;
}

void MyCircle::setCenter(int x, int y){
	this->x=x;
	this->y=y;
}

void MyCircle::setRadius(int r){
	this->r=r;
}

void MyCircle::Draw(){
	circle(x,y,r);
	cout<<Screen::getInstance()->getWidth()<<" "<<Screen::getInstance()->getHeight()<<" "<<endl;
	cout<<x<<" "<<y<<" "<<r<<endl;
	cout<<R<<" "<<G<<" "<<B<<endl;
}

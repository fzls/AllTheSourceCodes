#include "MyShape.h"

MyShape::MyShape(){
	R=255;
	G=255;
	B=255;
	enter = "enter myshape";
	leave = "leave myshape";
}
void MyShape::setColor(int R,int G,int B){
	this->R=R;
	this->G=G;
	this->B=B;
}
int MyShape::getR() const{
	return R;
}
int MyShape::getG() const{
	return G;
}
int MyShape::getB() const{
	return B;
}

#include "MyRectangle.h"
#include <graphics.h>
#include <iostream>
using namespace std;
void MyRectangle::setColor(int R, int G, int B){
	this->R=R;
	this->G=G;
	this->B=B;
}

MyRectangle::MyRectangle() {
	this->leftX = 10;
	this->leftY = 10;
	this->rightX = 100;
	this->rightY = 100;
	this->R=255;
	this->G=255;
	this->B=255;
//	this->pScreen = new Screen();
//	outtextxy((leftX+rightX)/2+10,(leftY+rightY)/2+10,"myrectangle");

	cout << "myrectangle" << endl;
}

//MyRectangle::MyRectangle(int leftX, int leftY, int rightX, int rightY, Screen* pScreen){
MyRectangle::MyRectangle(int leftX, int leftY, int rightX, int rightY){
	this->leftX = leftX;
	this->leftY = leftY;
	this->rightX = rightX;
	this->rightY = rightY;
	this->R=255;
	this->G=255;
	this->B=255;
//	this->pScreen = new Screen(pScreen->getWidth(),pScreen->getHeight());//before you make assignment to a object, make sure that you have alloc memory for it
//	this->pScreen = pScreen;
//	outtextxy((leftX+rightX)/2+10,(leftY+rightY)/2+10,"myrectangle");
	cout << "myrectangle" << endl;

}

void MyRectangle::setCoordinations(int leftX, int leftY, int rightX, int rightY) {
	this->leftX = leftX;
	this->leftY = leftY;
	this->rightX = rightX;
	this->rightY = rightY;
}

//void MyRectangle::setScreen(const Screen& screen) {
//	this->pScreen->setScreen(screen.getWidth(), screen.getHeight());
//}

void MyRectangle::Draw() {
//	if (this->leftX > 0 && this->leftX < this->pScreen->getWidth()
//	        && this->leftY > 0 && this->leftY < this->pScreen->getWidth()
//	        && this->rightX > 0 && this->rightX < this->pScreen->getHeight()
//	        && this->rightY > 0 && this->rightY < this->pScreen->getHeight()
//	   ) {
   	rectangle(leftX,rightY,rightX,leftY);
//   	xyprintf(leftX+10,leftY+10,"%d %d %d %d",leftX,leftY,this->pScreen->getWidth(),this->pScreen->getHeight());
	cout << leftX << " " << leftY << " " << rightX-leftX<< " " << rightY-leftY << " " << endl;
	cout << R <<" " <<G <<" "<<B<<endl;
//	}  
//	else {
//		outtextxy(leftX+10,leftY+10,"invalid myrectangle");
////		cout << "invalid myrectangle" << endl;
//	}
}


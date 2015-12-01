/*
+----------------------------------------------------------
*
* @authors: 椋庝箣鍑屾畤 <1054073896@qq.com>
* @FILE NAME:	 4_1.cpp
* @version:	 	 v1.0
* @Time: 		 2015-08-11 20:40:12
* @Description:
*1鍒涘缓涓や釜绫伙紝骞跺湪main鍑芥暟涓垱寤虹被鐨勫疄渚嬨€?
1. 鍒涘缓Screen绫?
2. 鍒涘缓MyRectangle绫?
3. 鍦╩ain()涓垱寤轰笂杩扮被鐨勫疄渚嬶紝骞惰皟鐢ㄥ璞＄殑鍑芥暟锛?0鍒嗭級
*
*
*
*
*
+----------------------------------------------------------
*/
using namespace std;
#include <iostream>
#include <cstdlib>
class Screen {
public:
	Screen();
	Screen(int width, int height);
	void setScreen(int width, int height);
	int getWidth()const ;
	int getHeight()const ;
private:
	int width;
	int height;
};
class MyRectangle {
public:
	MyRectangle();
	MyRectangle(int leftX, int leftY, int rightX, int rightY, Screen* pScreen);
	void setCoordinations(int leftX, int leftY, int rightX, int rightY);
	void setScreen(const Screen& screen);
	void Draw();
private:
	int leftX, leftY, rightX, rightY;
	Screen* pScreen;
};

int main() {
	int width, height;
	cin >> width >> height;
	Screen  screen (width, height);

	int leftX, leftY, rightX, rightY;
	cin >> leftX >> leftY >> rightX >> rightY;
	MyRectangle myRectangle1 (leftX, leftY, rightX, rightY, &screen);
	MyRectangle* myRectangles = new MyRectangle[2];

	myRectangles[1].setCoordinations(10, 300, 700, 500);
	myRectangles[1].setScreen(screen);

	myRectangle1.Draw();
	for (int i = 0; i < 2; i++) {
		myRectangles[i].setScreen(screen);
		(myRectangles + i) -> Draw();
	}

	delete [] myRectangles;

	cout << endl;
	system("pause");
	return 0;
}

Screen::Screen() {
	this->width = 640;
	this->height = 480;
	cout << "screen" << endl;
}

Screen::Screen(int width, int height) {
	if (width > 1000 || height > 1000) {
		cout << "invalid screen size" << endl;

		exit(-1);
	}
	this->width = width;
	this->height = height;
	cout << "screen" << endl;
}

void Screen::setScreen(int width, int height) {
	if (width > 1000 || height > 1000) {
		cout << "invalid screen size" << endl;
		system("pause");

		exit(-1);
	}
	this->width = width;
	this->height = height;
	cout << "screen" << endl;
}

int Screen::getWidth() const {
	return width;
}

int Screen::getHeight() const {
	return height;
}



MyRectangle::MyRectangle() {
	this->leftX = 0;
	this->leftY = 0;
	this->rightX = 0;
	this->rightY = 0;
	this->pScreen = new Screen();
	cout << "myrectangle" << endl;
}

MyRectangle::MyRectangle(int leftX, int leftY, int rightX, int rightY, Screen* pScreen) {
	this->leftX = leftX;
	this->leftY = leftY;
	this->rightX = rightX;
	this->rightY = rightY;
	this->pScreen = new Screen(pScreen->getWidth(), pScreen->getHeight()); //before you make assignment to a object, make sure that you have alloc memory for it
	// this->pScreen = pScreen;
	cout << "myrectangle" << endl;

}

void MyRectangle::setCoordinations(int leftX, int leftY, int rightX, int rightY) {
	this->leftX = leftX;
	this->leftY = leftY;
	this->rightX = rightX;
	this->rightY = rightY;
}

void MyRectangle::setScreen(const Screen& screen) {
	this->pScreen->setScreen(screen.getWidth(), screen.getHeight());
}

void MyRectangle::Draw() {
	if (this->leftX > 0 && this->leftX < this->pScreen->getWidth()
	        && this->leftY > 0 && this->leftY < this->pScreen->getWidth()
	        && this->rightX > 0 && this->rightX < this->pScreen->getHeight()
	        && this->rightY > 0 && this->rightY < this->pScreen->getHeight()
	   ) {
		cout << leftX << " " << leftY << " " << this->pScreen->getWidth() << " " << this->pScreen->getHeight() << " " << endl;
	}
	else {
		cout << "invalid myrectangle" << endl;
	}
}



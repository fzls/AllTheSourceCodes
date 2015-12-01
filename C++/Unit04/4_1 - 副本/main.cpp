/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 4_1.cpp
* @version:	 	 v1.0
* @Time: 		 2015-08-11 20:40:12
* @Description:
*1创建两个类，并在main函数中创建类的实例。
1. 创建Screen类
2. 创建MyRectangle类
3. 在main()中创建上述类的实例，并调用对象的函数（20分）
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
#include "Screen.h"
#include "MyRectangle.h"
#include <graphics.h>

int main() {
	int width, height;
//	initgraph(800,640);
//	width= getInteger("Input the width");
//	height = getInteger("Input the height");
	cin >> width >> height;
	Screen  screen (width, height);

	int leftX, leftY, rightX, rightY;
	leftX=getInteger("Input the leftX");
	leftY=getInteger("Input the leftY");
	rightX=getInteger("Input the rightX");
	rightY=getInteger("Input the rightY");
//	cin >> leftX >> leftY >> rightX >> rightY;
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

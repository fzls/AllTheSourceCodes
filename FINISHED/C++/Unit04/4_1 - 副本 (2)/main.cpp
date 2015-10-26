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
#include "MyCircle.h"
#include <graphics.h>
Screen* Screen::instance;
int main() {
  int width, height;
  cin >> width >> height;
  Screen::getInstance(width, height);
  Screen::getInstance();
   
  int leftX, leftY, rightX, rightY;
  cin >> leftX >> leftY >> rightX >> rightY;
  MyRectangle myRectangle(leftX, leftY, rightX, rightY);
  myRectangle.setColor(0, 0, 0xff);
  myRectangle.Draw();
 
  int centerX, centerY, radius;
  cin >> centerX >> centerY >> radius;
  MyCircle myCircles[2];
  (myCircles + 1)->setCenter(centerX, centerY);
  myCircles[1].setRadius(radius);
  myCircles[0].Draw();
  myCircles[1].Draw();
  
  MyCircle myCircle(myCircles[1]);
  myCircle.Draw();
  
  Screen::deleteInstance();
   
  cin.get();
  return 0;
}

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
#include <typeinfo>
#include "Screen.h"
#include "MyRectangle.h"
#include "MyCircle.h"
#include <graphics.h>
Screen* Screen::instance;

MyShape* createShape(char shapeType);

int main() {
  const int SHAPENUMBER = 5;
  Screen::getInstance();
  Screen::getInstance();
   
  char shapeType;
  MyShape* shapes[SHAPENUMBER];
  for(int i = 0; i < SHAPENUMBER; i++) {
    cout << "input shape type" << endl;
    cin >> shapeType;
    shapes[i] = createShape(shapeType);
  }
  cout << endl; 
   
   
  MyRectangle* myrectangle;
  MyCircle* mycircle;
  for(int i = 0; i < SHAPENUMBER; i++) {
    mycircle = dynamic_cast<MyCircle*>(shapes[i]);
    myrectangle = dynamic_cast<MyRectangle*>(shapes[i]);
    if ( (mycircle != 0) || (myrectangle != 0)) {
      shapes[i]->setColor(shapeType+i, shapeType+2*i, shapeType+3*i);
      if( typeid(*shapes[i]) == typeid(MyRectangle)) {
        myrectangle -> setCoordinations(10+10*i, 10+10*i, 400+10*i, 200+10*i); 
      } else {
        mycircle -> setCenter(200+10*i, 200+10*i);
        mycircle -> setRadius(50+10*i);
      }   
      shapes[i]->Draw();
    } else {
      cout << "invalid shape" << endl;
    }      
  }
   
  for(int i = 0; i< SHAPENUMBER; i++) {
      delete shapes[i];
  }
   
  Screen::deleteInstance();
   
  cin.get();
  return 0;
}

MyShape* createShape(char shapeType){
	switch(shapeType){
		case 'c' : return new MyCircle();break;
		case 'r' : return new MyRectangle();break;
		default : return 0;break;
		
	}
}









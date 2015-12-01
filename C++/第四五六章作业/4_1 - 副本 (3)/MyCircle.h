#pragma once
#include "MyShape.h"
class MyCircle:public MyShape{
	public:
//		void setColor(int R,int G,int B);
		MyCircle();
		MyCircle(int x,int y,int r);
		MyCircle(const MyCircle& mycircle);
		void setCenter(int x, int y);
		void setRadius(int r);
		void Draw();
	private:
//		int R,G,B;
		int x,y,r;
};

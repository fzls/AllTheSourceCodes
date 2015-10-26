/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 8_1.cpp
* @version:
* @Time: 		 2015-08-14 19:17:46
* @Description:  在如下给定的代码中，为 MyCircle 类添加关系运算符 >、<、>=、<=、==、!= ，实现按照半径对 MyCircle 对象进行比较。

要求
关系运算符重载后的返回值均为 bool 类型
不得修改所给的代码
*
+----------------------------------------------------------
*/
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class MyShape {
protected:
	int R_, G_, B_;

	string colorToString() {
		stringstream ss;
		ss << R_ << " " << G_ << " " << B_;
		return ss.str();
	}
public:
	void setColor(int R, int G, int B) {
		R_ = R; G_ = G, B_ = B;
	}
	int getR() {
		return R_;
	}
	int getG() {
		return G_;
	}
	int getB() {
		return B_;
	}
	virtual void Draw() = 0;
	MyShape() {
		R_ = 255; G_ = 255, B_ = 255;
	}
};

class MyCircle : public MyShape {
private:
	int x_, y_, radius_;

public:
	MyCircle(int x, int y, int radius) {
		x_ = x;
		y_ = y;
		radius_ = radius;
	}

	MyCircle() {
		x_ = y_ = 200;
		radius_ = 100;
	}

	MyCircle(MyCircle& aCircle) {
		x_ = aCircle.x_;
		y_ = aCircle.y_;
		radius_ = aCircle.radius_;
		R_ = aCircle.getR();
		G_ = aCircle.getG();
		B_ = aCircle.getB();
	}
	void setCenter(int x, int y) {
		x_ = x;
		y_ = y;
	}

	void setRadius(int radius) {
		radius_ = radius;
	}

	void Draw() {
	}
	bool MyCircle::operator<(MyCircle &secondMyCircle) ;
	bool MyCircle::operator>(MyCircle &secondMyCircle);
	bool MyCircle::operator>=(MyCircle &secondMyCircle);
	bool MyCircle::operator<=(MyCircle &secondMyCircle);
	bool MyCircle::operator==(MyCircle &secondMyCircle);
	bool MyCircle::operator!=(MyCircle &secondMyCircle);
	//----在此处添加关系运算符  >、<、>=、<=、==、!=  的重载原型声明
};
bool MyCircle::operator<(MyCircle &secondMyCircle) {
	return (this->radius_ < secondMyCircle.radius_);
}
bool MyCircle::operator>(MyCircle &secondMyCircle) {
	return (this->radius_ > secondMyCircle.radius_);

}
bool MyCircle::operator>=(MyCircle &secondMyCircle) {
	return (this->radius_ >= secondMyCircle.radius_);

}
bool MyCircle::operator<=(MyCircle &secondMyCircle) {
	return (this->radius_ <= secondMyCircle.radius_);

}
bool MyCircle::operator==(MyCircle &secondMyCircle) {
	return (this->radius_ == secondMyCircle.radius_);

}

bool MyCircle::operator!=(MyCircle & secondMyCircle) {
	return (this->radius_ != secondMyCircle.radius_);

}
//----在此处添加关系运算符的重载定义

int main() {
	int r1, r2, r3 = 0;
	cin >> r1 >> r2 >> r3;
	MyCircle c1, c2, c3;
	c1.setRadius(r1);
	c2.setRadius(r2);
	c3.setRadius(r3);

	cout << (c1 > c2) << endl;
	cout << (c1 < c2) << endl;
	cout << (c2 >= c3) << endl;
	cout << (c2 <= c3) << endl;
	cout << (c1 == c3) << endl;
	cout << (c1 != c3) << endl;

	cout << endl;
	system("pause");
	return 0;
}


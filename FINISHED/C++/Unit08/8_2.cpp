/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 8_2.cpp
* @version:
* @Time: 		 2015-08-14 19:30:28
* @Description:  题目内容：

在本单元作业1的基础上，在MyCircle类中添加对数组下标运算符的重载。
要求：
按照数组下标由小到大，数组下标运算符按照次序分别返回圆心x坐标，圆心y坐标，圆的半径。
下标超出范围，则返回带符号整型数中最小的值
可以为MyCircle类添加数据域成员并且修改其函数成员。
*
+----------------------------------------------------------
*/
#include <iostream>
#include <string>
#include <sstream>
#include <limits>

using namespace std;
static int MIN_MINUS_INTEGER;


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
	int min_;

public:
	MyCircle(int x, int y, int radius) {
		x_ = x;
		y_ = y;
		radius_ = radius;
		min_ = MIN_MINUS_INTEGER;
	}

	MyCircle() {
		x_ = y_ = 200;
		radius_ = 100;
		min_ = MIN_MINUS_INTEGER;
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
	int&  MyCircle::operator[](const int& index);
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

int&  MyCircle::operator[](const int &index) {
	if (index == 0) {
		return x_;
	}
	else if (index == 1) {
		return y_;
	}
	else if (index == 2) {
		return radius_;
	}
	else return min_;
}


//----在此处添加关系运算符的重载定义

int main() {
	// for (MIN_MINUS_INTEGER = 1; MIN_MINUS_INTEGER > 0; MIN_MINUS_INTEGER++);//get min num by ourself
	MIN_MINUS_INTEGER = numeric_limits<int>::min();//get it by given function
	int x, y, r = 0;
	cin >> x >> y >> r;
	MyCircle c1(x, y, r);
	MyCircle c2;
	c2[2] = x;
	for (int i = 0; i <= 3; i++) {
		cout << c1[i] << endl;
		cout << c2[i - 1] << endl;
	}

	cout << endl;
	system("pause");
	return 0;
}


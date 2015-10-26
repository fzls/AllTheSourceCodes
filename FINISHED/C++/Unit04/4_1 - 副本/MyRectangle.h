#include "Screen.h"
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


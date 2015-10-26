#include "Screen.h"
class MyRectangle {
public:
	MyRectangle();
//	MyRectangle(int leftX, int leftY, int rightX, int rightY, Screen* pScreen);
	MyRectangle(int leftX, int leftY, int rightX, int rightY);
	void setCoordinations(int leftX, int leftY, int rightX, int rightY);
//	void setScreen(const Screen& screen);
	void Draw();
	void setColor(int R, int G, int B);
private:
	int leftX, leftY, rightX, rightY;
	int R,G,B;
//	Screen* pScreen;
};


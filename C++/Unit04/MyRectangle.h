#pragma once
class MyRectangle {
public:
	MyRectangle() {
		this.leftX = 0;
		this.leftY = 0;
		this.rightX = 0;
		this.rightY = 0;
		// this.pScreen = pScreen;
		cout << "myrectangle" << endl;
	}
	MyRectangle(int leftX, int leftY, int rightX, int rightY, Screen* pScreen) {
		this.leftX = leftX;
		this.leftY = leftY;
		this.rightX = rightX;
		this.rightY = rightY;
		this.pScreen = pScreen;
		cout << "myrectangle" << endl;

	}
	void setCoordinations(int leftX, int leftY, int rightX, int rightY) {
		this.leftX = leftX;
		this.leftY = leftY;
		this.rightX = rightX;
		this.rightY = rightY;
	}
	void setScreen(const Screen& pScreen) {
		this.pScreen = pScreen;
	}
	void Draw() {
		if (this.leftX > 0 && this.leftX < this.pScreen->getWidth()
		        && this.leftY > 0 && this.leftY < this.pScreen->getWidth()
		        && this.rightX > 0 && this.rightX < this.pScreen->getHeight()
		        && this.rightY > 0 && this.rightY < this.pScreen->getHeight()
		   ) {
			cout << leftX << " " << leftY << " " << this.pScreen->getWidth() << " " << this.pScreen->getHeight() << " " << endl;
		}
		else {
			cout << "invalid myrectangle" << endl;
		}
	}
private:
	int leftX, leftY, rightX, rightY;
	Screen* pScreen;
}


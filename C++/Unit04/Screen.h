#pragma once
class Screen {
public:
	Screen() {
		this.width = 640;
		this.height = 480;
		cout << "screen" << endl;
	}
	Screen(int width, int height) {
		if (width > 1000 || height > 1000) {
			cout << "invalid screen size" << endl;
			exit();
		}
		this.width = width;
		this.height = height;
		cout << "screen" << endl;
	}
	void setScreen(int width, int height) {
		if (width > 1000 || height > 1000) {
			cout << "invalid screen size" << endl;
			exit();
		}
		this.width = width;
		this.height = height;
		cout << "screen" << endl;
	}
	int getWidth() {
		return width;
	}
	int getHeight() {
		return height;
	}
private:
	int width;
	int height;
};



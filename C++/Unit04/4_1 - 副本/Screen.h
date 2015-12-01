#pragma once 
class Screen {
public:
	Screen();
	Screen(int width, int height);
	~Screen();
	void setScreen(int width, int height);
	int getWidth()const ;
	int getHeight()const ;
private:
	 int width;
	 int height;
};



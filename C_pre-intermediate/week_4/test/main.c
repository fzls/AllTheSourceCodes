#include "acllib.h"
#include <stdio.h>

void mouseListener(int x, int y, int button, int event)
{
	static int ox = 0;
	static int oy = 0;
	static int check = 1;
//	printf("x=%d,y=%d,button=%d,event=%d\n",x,y,button,event);
	//	while(1);
	if (event == 0 || event == 2)
	{
		check = event;
	}
	beginPaint();
	if (check == 0)
	{
		line(ox, oy, x, y);
//		lineTo(x,y);
	}


	endPaint();
	ox = x;
	oy = y;
}

void keyListener(int key, int event)
{
	printf("key=%d,event=%d\n", key, event);

}

void timerListener(int id)
{
	static int cnt = 0;
	printf("id=%d\n", id);
	if (id == 0)
	{
		cnt++;
		if (cnt == 5) {
			cancelTimer(0);
		}
	}
}

int Setup()
{
	initConsole();
	printf(" ‰»ÎøÌ∂»£∫");
	int width;
	scanf("%d", &width);
	initWindow("test", 100, 100, width, width);
	registerMouseEvent(mouseListener);
	registerKeyboardEvent(keyListener);
	registerTimerEvent(timerListener);
	startTimer(0, 500);
	startTimer(1, 1000);
	startTimer(2, 2000);


	beginPaint();


	paintText(50, 50, "this is test program- -!");
	setPenColor(BLUE);
	setPenWidth(1);
	setPenStyle(PEN_STYLE_DASHDOTDOT);
	line(20, 20, width - 20, width - 20);
	putPixel(100, 150, RGB(255, 250, 0));
	endPaint();
	return 0;
}

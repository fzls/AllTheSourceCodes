/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 7_2.cpp
* @version:
* @Time: 		 2015-08-13 22:28:14
* @Description:  第7单元 - 单元作业第2题说明 （概要）

本材料是对单元作业第2题第1小题的概要说明。如果你根据概要说明，还无法顺利完成作业，那么可以参考【第7单元 - 单元作业第2题说明 （详细）】

在本单元作业第1题的基础上，仅修改 main() 函数代码，实现如下功能：

用 string 对象保存文件名 "screen.txt"；然后创建 fstream 对象，再调用open函数，使用读写模式打开文件。
使用读写模式打开的文件，如果文件不存在，则会打开失败。在这种情况下需要使用单独的“写模式”打开文件然后再关闭该文件，即可创建一个长度为0的空文件。然后再以读写模式打开该文件。
从打开的文件中，读取屏幕的宽和高。如果读取失败，则从键盘读入屏幕的宽和高。同时，要清除文件流的状态位，否则后面的所有文件操作代码均会失败。
保留原 main() 函数中的代码：
   screen = Screen::getInstance(width, height);
   screen = Screen::getInstance();
5. 在文件的头部开始，写入屏幕的宽(screen->getWidth())和屏幕的高度(screen->getHeight())
6. 如果写文件出错，则提示错误信息然后关闭文件并返回-1
7. 从文件中读取刚刚写入的屏幕的宽和高，然后显示到屏幕上
8. 最后关闭文件

*
+----------------------------------------------------------
*/
#include <iostream>
#include <limits>
#include <cstdlib>
#include <fstream>
using namespace std;

class Screen {
private:
	//----补充多个数据域成员
	int width, height;
	static Screen* instance;

	// 在Screen类中获取/释放图形窗口资源，是一种RAII方法
	//   关于RAII，可以参见异常处理单元的材料
	Screen() {
		this->width = 640;
		this->height = 480;
		// 如果启用了图形库，则将初始化图形模式的函数置于此处
		// initgraph(width_, height_);
	};
	Screen(int width, int height) {
		this->width = width;
		this->height = height;
	}
	~Screen () {
		// 如果启用了图形库，则将关闭图形模式的函数置于此处
		// closegraph();
		delete instance;
	}

public:
	//----补充 getWidth() 与 getHeight() 函数，
	int getWidth() {
		return width;
	}

	int getHeight() {
		return height;
	}

	static Screen* getInstance(unsigned int width = 640, unsigned int height = 480) {
		// 单例模式
		//----补充函数体
		static Screen* instance;
		if (width <= 0 || height <= 0 || width > 1366 || height > 768) {
			cout << "input error" << endl;
			system("pause");

			exit(-1);
		}
		if (instance == 0) {
			instance = new Screen(width, height);
		}
		return instance;
	}
};

Screen* Screen::instance = 0;
//----补充Screen类的特殊数据成员初始化语句

int main() {
	int width, height;
	Screen* screen = 0;

	cin >> width >> height;
	screen = Screen::getInstance(width, height);
	screen = Screen::getInstance();

	cout << screen->getWidth() << " " <<
	     screen->getHeight() << endl;
	cout << "part 2" << endl;
	fstream inout;
	inout.open("screen.txt", ios::out | ios::in);
	if (inout.fail()) {
		cout << "open file failed" << endl;
		inout.open("screen.txt", ios::out);
		inout.close();
		inout.open("screen.txt", ios::out | ios::in);
	}
	inout << screen->getWidth() << " " << screen->getHeight() << endl;
	if (inout.fail()) {
		cout << "write to file failed" << endl;
		exit(-1);
	}

	inout.close();
	inout.open("screen.txt", ios::out | ios::in);
	int width1 = 0, height1 = 0;
	inout >> width1 >> height1;
	if (inout.fail()) {
		cout << "can't read from file, please input the width and height" << endl;
		cin >> width1 >> height1;
	}
	cout << width1 << " " << height1 << endl;
	//


	inout.close();
// GCC及VC编译器在调试模式下会暂停，便于查看运行结果
#if ( defined(__DEBUG__) || defined(_DEBUG) )
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
#endif

	cout << endl;
	system("pause");
	return 0;
}




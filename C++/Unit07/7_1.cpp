/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 7_1.cpp
* @version:
* @Time: 		 2015-08-13 22:23:35
* @Description:  第7单元 - 单元作业第1题说明 (在线编程)

题目内容：
以单例模式创建一个屏幕Screen对象。

输入格式:
用空格分开的两个整数，代表屏幕分辨率

输出格式：
用空格分开的两个整数，代表屏幕分辨率。随后有换行符

输入样例：
800 600

输出样例：
800 600

具体要求：
请将如下代码中的缺失部分补全：
补全Screen类中的数据域成员，给出适当的数据类型
a. 代表屏幕宽和高的数据域成员
b. 保存单例对象地址的一个指针数据成员 instance
c. 注意数据域成员是否应该使用 static 关键字修饰
补充getWidth与getHeight函数
补全getInstance的函数体
补充Screen类的特殊数据成员初始化语句

对于getInstance函数，是单例模式的核心函数。关于单例模式及其示例代码，可以参见百度百科【单例模式】。 getInstance函数体主要流程为：
判断 instance 数据域成员是否指向一个 Screen 对象；
若 instance 未指向有效的 Screen 对象，则设置屏幕的高和宽；
然后创建一个 Screen 对象（使用 new 运算符），将该对象地址存入 instance
*
+----------------------------------------------------------
*/
#include <iostream>
#include <limits>
#include <cstdlib>
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

// GCC及VC编译器在调试模式下会暂停，便于查看运行结果
#if ( defined(__DEBUG__) || defined(_DEBUG) )
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
#endif

	cout << endl;
	system("pause");
	return 0;
}


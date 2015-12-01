#include<iostream>
#include <time.h>
#include <math.h>

const int max = 100;//累加的值
const int times = 1000000;//执行次数
double result;
using namespace std;
void fun_one(double);
void fun_two(double);
void time_cost(void (*)(double), double, int);


int main() {
    time_cost(fun_one, 1.1, times);
    time_cost(fun_two, 1.1, times);
    system("pause");

}

//传统方法
void fun_one(double x) {
    double sum = 1;
    for (int i = 1; i <= ::max; i++) {
        sum += (double)pow(x, i) / (double)i;
    }
    result = sum;
}
//第二种方法
void fun_two(double x) {
    double sum = 1 / (double)::max;
    for (int i = ::max; i > 0 ; i--) {
        sum = 1 / (double)(i - 1 + (i == 1)) + sum * x;
    }
    result = sum;
}

void time_cost(void (*fun)(double), double a, int times) {
    clock_t start, finish;
    double time_length;
    start = clock();//start存储的是当前的时刻
    {   //测试代码块
        while (times--) {
            fun(a);
        }
        cout << result << endl;
    }
    finish = clock();//finish存储的是结束的时刻
    time_length = (double)(finish - start) / CLOCKS_PER_SEC;//根据两个时刻的差，计算出运行的时间
    cout << "Time used is " << time_length << " second." << endl;
}

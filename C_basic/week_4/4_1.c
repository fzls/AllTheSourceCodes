/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 (1054073896@qq.com)
* @FILE NAME :4_1.c
* @version： 1.0
* @Time: 2015-07-18 22:28:13
* @Description:
* 题目内容：
我们认为2是第一个素数，3是第二个素数，5是第三个素数，依次类推。
现在，给定两个整数n和m，0<n<=m<=200，你的程序要计算第n个素数到第m个素数之间所有的素数的和，包括第n个素数和第m个素数。

输入格式:
两个整数，第一个表示n，第二个表示m。

输出格式：
一个整数，表示第n个素数到第m个素数之间所有的素数的和，包括第n个素数和第m个素数。

输入样例：
2 4

输出样例：
15
时间限制：500ms内存限制：32000kb
*
+----------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int isprime(int x);

int main() {
	int m, n, count = 0, sum = 0, i; //初始化
	printf("请输入n,m\n");
	scanf("%d%d", &n, &m);
	while (!(n > 0 && m >= n)) {
		scanf("%d%d", &n, &m);
	}
	// 使用模块化思想，将经常用到的功能（检验素数）使用函数来实现。
	for (i = 1; count < n; )
	{
		if (isprime(++i))
			count++;

	}
	// --i;//退出循环时i-1为第n个素数，故此处应将i自减，否则后续计算会出现错误
	//v2：更换i自增的位置，则无需对i进行特殊处理2015-07-18 23:15:04
	for (; count <= m; ++i)
	{
		if (isprime(i))
		{
			count++;
			sum += i;
		}
	}
	printf("sum of the primes is %d\n", sum);
	system("pause");
	return 0;
}

int isprime(int x) {
	int i, prime = 1;
	double sqrt_ = sqrt(x);
	if (x == 0 || x == 1)
	{
		prime = 0;
	}
	for ( i = 2; i <= sqrt_; ++i)
	{
		if (x % i == 0)
		{
			prime = 0;
			break;

		}
	}
	return prime;
}

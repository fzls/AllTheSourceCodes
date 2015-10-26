/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 (1054073896@qq.com)
* @FILE NAME :5_1.c
* @version： v1.0
* @Time: 2015-07-19 10:54:43
* @Description:
1分解质因数（5分）
题目内容：
每个非素数（合数）都可以写成几个素数（也可称为质数）相乘的形式，这几个素数就都叫做这个合数的质因数。比如，6可以被分解为2x3，而24可以被分解为2x2x2x3。
现在，你的程序要读入一个[2,100000]范围内的整数，然后输出它的质因数分解式；当读到的就是素数时，输出它本身。

输入格式:
一个整数，范围在[2,100000]内。

输出格式：
形如：
n=axbxcxd
或
n=n
所有的符号之间都没有空格，x是小写字母x。

输入样例：
18
输出样例：
18=2x3x3

时间限制：500ms内存限制：32000kb
*
+----------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int isprime(int x);
int main() {
	int number;
	scanf("%d", &number);
	while (!(number >= 2 && number <= 100000)) {
		printf("输入有误，请重新输入一个整数，范围在[2,100000]内。\n");
		scanf("%d", &number);

	}
	printf("%d=", number);
	for (int i = 1; number > 1; )
	{
		if (isprime(++i)) {
			while (number % i == 0) {
				printf("%d", i);
				if (number != i)
				{
					printf("x");
				}
				number /= i;
			}
		}
	}
	printf("\n");
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

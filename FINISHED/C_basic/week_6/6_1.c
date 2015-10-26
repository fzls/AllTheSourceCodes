/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME :6_1.c
* @version： v1.0
* @Time: 2015-07-19 21:46:45
* @Description:
*
1多项式加法（5分）
题目内容：
一个多项式可以表达为x的各次幂与系数乘积的和，比如：

现在，你的程序要读入两个多项式，然后输出这两个多项式的和，也就是把对应的幂上的系数相加然后输出。
程序要处理的幂最大为100。

输入格式:
总共要输入两个多项式，每个多项式的输入格式如下：
每行输入两个数字，第一个表示幂次，第二个表示该幂次的系数，所有的系数都是整数。第一行一定是最高幂，最后一行一定是0次幂。
注意第一行和最后一行之间不一定按照幂次降低顺序排列；如果某个幂次的系数为0，就不出现在输入数据中了；0次幂的系数为0时还是会出现在输入数据中。

输出格式：
从最高幂开始依次降到0幂，如：
2x6+3x5+12x3-6x+20
注意其中的x是小写字母x，而且所有的符号之间都没有空格，如R果某个幂的系数为0则不需要有那项。

时间限制：500ms内存限制：32000kb
*
+----------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_POWER 100
int main() {
	int power, coefficient, count = 0, i;
	//利用polynomial数组寄存多项式，下标表示幂次，数值表示对应系数
	int polynomial[MAX_POWER] = {0};
	//利用count计数，若count变为2则说明出现两次零次幂，即输入完成
	while (count < 2) {
		scanf("%d%d", &power, &coefficient);
		polynomial[power] += coefficient;
		if (power == 0)
		{
			++count;
		}
	}
	// 输出系数非0的非0次幂，以及零次幂系数，并按幂次降序排列
	// 为处理+-号，先将第一个输出
	for (i = MAX_POWER - 1; i > 0; i--) {
		if (polynomial[i]) {
			printf("%dx%d", polynomial[i], i );
			break;
		}
	}

	for (i--; i > 0; i--) {
		if (polynomial[i]) {
			if (polynomial[i] > 0) {
				printf("+");
			}
			printf("%dx", polynomial[i]);
			if (i > 1)
				printf("%d", i);
		}
	}

	if (polynomial[0] > 0) {
		printf("+");
	}
	else
		printf("-");
	printf("%d\n", polynomial[0]);

	printf("\n");
	system("pause");
	return 0;
}


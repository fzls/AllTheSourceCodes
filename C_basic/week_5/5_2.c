/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 (1054073896@qq.com)
* @FILE NAME :5_2.c
* @version： v1.0
* @Time: 2015-07-19 11:09:44
* @Description:
2完数（5分）
题目内容：
一个正整数的因子是所有可以整除它的正整数。而一个数如果恰好等于除它本身外的因子之和，这个数就称为完数。例如6=1＋2＋3(6的因子是1,2,3)。
现在，你要写一个程序，读入两个正整数n和m（1<=n<m<1000），输出[n,m]范围内所有的完数。
提示：可以写一个函数来判断某个数是否是完数。

输入格式:
两个正整数，以空格分隔。

输出格式：
其间所有的完数，以空格分隔，最后一个数字后面没有空格。如果没有，则输出一个空行。

输入样例：
1 10

输出样例：
6
时间限制：800ms内存限制：32000kb
*
+----------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>

int isperfect(int x);

int main() {
	int n, m, temp, i;
	scanf("%d%d", &n, &m);
	i = n;
	while (!(isperfect(i)) && i <= m) {
		i++;
	}
	if (isperfect(i))
	{
		temp = i;
	}
	else
		temp = 0;
	for (++i; i <= m; i++) {
		if (isperfect(i)) {
			printf("%d ", temp);
			temp = i;
		}
	}
	if (temp)
		printf("%d\n", temp	);
	system("pause");
	return 0;
}

int sum = 0;
for (int i = 1; i < x; i++) {
	if (x % i == 0) {
		sum += i;
	}
}
if (sum == x) {
	return 1;
}
else
	return 0;
}

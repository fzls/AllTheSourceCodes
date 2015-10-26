/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 (1054073896@qq.com)
* @FILE NAME :4_2.c
* @version：v1.0
* @Time: 2015-07-18 23:15:44
* @Description:
* 你的程序要读入一个整数，范围是[-100000,100000]。然后，用汉语拼音将这个整数的每一位输出出来。
如输入1234，则输出：
yi er san si
注意，每个字的拼音之间有一个空格，但是最后的字后面没有空格。当遇到负数时，在输出的开头加上“fu”，如-2341输出为：
fu er san si yi

输入格式:
一个整数，范围是[-100000,100000]。

输出格式：
表示这个整数的每一位数字的汉语拼音，每一位数字的拼音之间以空格分隔，末尾没有空格。

输入样例：
-30

输出样例：
fu san ling
时间限制：500ms内存限制：32000kb
*
+----------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
void print_final(int x);
void print_part(int x);
void print(int x);

int main() {
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	int x;
	scanf("%d", &x);
	while (!(x >= -100000 && x <= 100000)) {
		printf("您的输入有误，请输入一个整数，范围是[-100000,100000]。\n");
		scanf("%d", &x);
	}
	if (x < 0)
	{
		printf("fu ");
		x = -x;
	}
	print(x);
	printf("\n");
	system("pause");
	return 0;
}

void print_final(int x) {
	switch (x) {
	case 0: printf("ling"); break;
	case 1: printf("yi"); break;
	case 2: printf("er"); break;
	case 3: printf("san"); break;
	case 4: printf("si"); break;
	case 5: printf("wu"); break;
	case 6: printf("liu"); break;
	case 7: printf("qi"); break;
	case 8: printf("ba"); break;
	case 9: printf("jiu"); break;

	}
}
void print_part(int x) {
	if (x > 0) {
		print_part(x / 10);
		switch (x % 10) {
		case 0: printf("ling "); break;
		case 1: printf("yi "); break;
		case 2: printf("er "); break;
		case 3: printf("san "); break;
		case 4: printf("si "); break;
		case 5: printf("wu "); break;
		case 6: printf("liu "); break;
		case 7: printf("qi "); break;
		case 8: printf("ba "); break;
		case 9: printf("jiu "); break;
		}
	}

}

void print(int x) { //由于最右端与其他部分处理情况不同，可以分别写一个函数为其实现相应功能
	print_part(x / 10);
	print_final(x % 10);
}

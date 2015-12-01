/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 TM_FILENAME
* @version:	 v1.0
* @Time: 		 2015-07-20 01:17:29
* @Description: 1单词长度（4分）
题目内容：
你的程序要读入一行文本，其中以空格分隔为若干个单词，以‘.’结束。你要输出这行文本中每个单词的长度。这里的单词与语言无关，可以包括各种符号，比如“it's”算一个单词，长度为4。注意，行中可能出现连续的空格。

输入格式:
输入在一行中给出一行文本，以‘.’结束，结尾的句号不能计算在最后一个单词的长度内。

输出格式：
在一行中输出这行文本对应的单词的长度，每个长度之间以空格隔开，行末没有最后的空格。

输入样例：
It's great to see you here.

输出样例：
4 5 2 3 3 4
时间限制：500ms内存限制：32000kb
*
+----------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE  1
// 一般思路是每当一个单词结束时，输出该单词词数后，判断该单词是否为最后一个，若不是则再输出一个空格
// 然是难以判断是否是最后一个单词，故而可以改变思路，先将第一个输出，此后每次输出词数前先输出一个空格，再输出词数，则可解决该问题（因为第一个总是确定的，而最后一个的位置难以判断）
int main() {
	char ch;
	int count = 0, space = 0, flag = FALSE;/*flag若为真，则表示不是第一个单词*/
	while ((ch = getchar()) != '.') {//遇到.时结束循环
		// 若非空格则count加一，并置space为0，表示此次字符非空格
		if (ch != ' ')
		{
			++count;
			space = 0;
		}
		else {
			if (!space) {/*若上次字符非空格，则进行输出*/
				if (flag) {/*判断是否是第一个，若非第一个，则先输出一个空格，再输出次数，否则不输出空格*/
					printf(" ");
				}
				printf("%d", count);
				flag = TRUE;/*因为已至少运行一次，故不再可能是第一个，故将flag置为true*/
				count = 0;//将count置零
			}
			space = 1;/*因为本次字符为空格，故将space标记为1*/
		}
	}
	//对于.紧跟最后一个单词的情况，上述代码无法解决，故须对此种情况进行特殊处理如下
	if (count) {
		printf(" %d\n", count);
		count = 0;
	}

	printf("\n");
	system("pause");
	return 0;
}


// #include <stdio.h>
// #include <stdbool.h>
// #include <stdlib.h>

// int main()
// {
// //    freopen("in.txt", "r", stdin); // for test

// 	char ch;
// 	int cnt;
// 	bool flag;

// 	flag = false;
// 	cnt = 0;
// 	while ((ch = getchar()) && ch != '.')
// 	{
// 		if (ch != ' ')
// 			cnt++;
// 		else if (cnt != 0)
// 		{
// 			if (flag)
// 				printf(" ");
// 			printf("%d", cnt);
// 			flag = true;
// 			cnt = 0;
// 		}
// 	}
// 	if (cnt != 0)
// 	{
// 		if (flag)
// 			printf(" ");
// 		printf("%d\n", cnt);
// 	}
// //    fclose(stdin); // for test
// 	system("pause");
// 	return 0;
// }

/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 TM_FILENAME
* @version:	 v1.0
* @Time: 		 2015-07-20 20:48:46
* @Description: 1删除字符串中的子串（5分）
题目内容：
输入2个字符串S1和S2，要求删除字符串S1中出现的所有子串S2，即结果字符串中不能包含S2。
提示：输入数据的设计使得不可能出现输出为空的情况。

输入格式:
输入分别给出2个每个不超过80个字符长度的不带空格的非空字符串，对应S1和S2。

输出格式：
在一行中输出删除字符串S1中出现的所有子串S2后的结果字符串。

输入样例：
Thisisatest is

输出样例：
Thatest
时间限制：500ms内存限制：32000kb
*
+----------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENTH 81

void Delete(char *s1, char* s2);
int main() {
	char s1[LENTH], s2[LENTH];
	gets(s1);
	gets(s2);
	Delete(s1, s2);
	printf("%s\n", s1);

	printf("\n");
	system("pause");
	return 0;
}

void Delete(char *s1, char *s2) {
	int i, lenth_1 = strlen(s1), lenth_2 = strlen(s2), flag = 0;//flag用于判断是否匹配成功，若匹配成功则i不递增，否则递增
	for (i = 0; i <= lenth_1 - lenth_2; ) {
		int index_1 = i, index_2 = 0;
		// 注意循环判断条件的设置，另外最好自增不要放在循环条件里，放在循环体里面可能会更加合适。
		// 寻找匹配部分
		while (index_2 < lenth_2 && s1[index_1] == s2[index_2]) {
			index_1++; index_2++;
		}
		// 若匹配成功，则对s1进行匹配处删除操作
		if (index_2 == lenth_2 ) {
			for (int j = index_1 - lenth_2; j <= lenth_1; j++) {
				s1[j] = s1[j + lenth_2];
			}
			flag = 1;
			lenth_1 = strlen(s1);
		}
		if (flag == 0) {i++;}
		else flag = 0;//匹配成功后将flag置零
	}
}


/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 p2.cpp
* @version:
* @Time:
* @Description:
*
+----------------------------------------------------------
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;



int main() {
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);



	cout << endl;
	system("pause");
	return 0;
}

/* 伪代码，与八皇后问题类似，采用回溯法解决 */
bool solve( string strings, set<string> wordlist) {
	string word;
	bool result = false;
	while (word = find_next_first_char_is(strings[0], wordlist)) { //在字典中查找下一个首字母为当前字符串首字母的单词（待实现）
		if (strcmp(word, s.substr(0, c.size()))) //如果该单词为当前字符串前缀，则递归解决后面部分的匹配问题，否则继续试探下一个备选单词
			result = solve(strings.substr(c.size()), wordlist);
		if (result) //如果找到，则跳出循环
			break;
	}
	return result;//返回结果
}

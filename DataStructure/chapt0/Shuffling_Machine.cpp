/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 Shuffling_Machine.cpp
* @version:
* @Time: 		 2015-08-27 20:03:50
* @Description:  http://www.patest.cn/contests/mooc-ds/00-自测5. Shuffling Machine (20)
*
+----------------------------------------------------------
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;
void initialize(vector<string>& cards);
void shuffle(vector<string>& cards, const vector<int>& transform);

int main() {
	int k, t;
	std::vector<string> cards(54, "") ;
	initialize(cards);
	std::vector<int> transform ;

	cin >> k;
	for (int i = 0; i < 54; i++) {
		cin >> t;
		transform.push_back(t - 1) ;//because we use 0~53 to present the card, so t should minus 1;
	}

	while (k--) {
		shuffle(cards, transform);
	}

	for (auto i = cards.cbegin(); i != cards.cend(); i++) {
		cout << *i << (i == (cards.cend() - 1) ? "" : " ");
	}

	// cout << endl;
	// system("pause");
	return 0;
}
void initialize(vector<string>& cards) {
	string suits[5] = {"S", "H", "C", "D", "J"};
	string numbers[13] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13"};
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 13; j++)
			cards[i * 13 + j] = suits[i] + numbers[j];
	cards[52] = suits[4] + numbers[0];
	cards[53] = suits[4] + numbers[1];
}
void shuffle(vector<string>& cards, const vector<int>& transform) {
	std::vector<string> temp(54, "") ;
	for (int i = 0; i < 54; i++) {
		temp[transform[i]] = cards[i];

	}
	for (int i = 0; i < 54; i++)
		cards[i] = temp[i];

}

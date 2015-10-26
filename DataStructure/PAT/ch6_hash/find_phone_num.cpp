/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 find_phone_num.cpp
* @version:
* @Time: 		 2015-09-14 12:15:43
* @Description:11-散列1 电话聊天狂人   (25分)
*
+----------------------------------------------------------
*/
#include <iostream>
#include <vector>

using namespace std;

struct Counter
{
	Counter(int p , int t): phoneNum(p), times(t) {}
	int phoneNum;
	int times;
};

void hash_func(vector<Counter> &hashtable, int phone);
int main() {
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	int n;
	cin >> n;
	vector<Counter> hashtable(3 * n, Counter(0, 0));
	int receiver, caller;
	for (int i = 0; i < n; i++) {
		cin >> caller >> receiver;
		hash_func(hashtable, caller);
		hash_func(hashtable, receiver);
		cout << "-----" << caller % 13 << " " << receiver % 13 << endl;
	}
	int index = 0;
	for (int i = 1; i < 3 * n; i++)
		if (hashtable[i].phoneNum != 0)
			// cout << i;
			if (hashtable[i].times > hashtable[index].times || (hashtable[i].times == hashtable[index].times && hashtable[i].phoneNum < hashtable[index].phoneNum))
				index = i;
	for (int i = 0; i < 3 * n; i++)
		cout << hashtable[i].phoneNum << " " << hashtable[i].times << endl;
	cout  << hashtable[index].phoneNum << " " << hashtable[index].times << endl;

	cout << endl;
	system("pause");
	return 0;
}

void hash_func(vector<Counter> &hashtable, int phone) {
	int n = static_cast<int>(hashtable.size()) ;
	int hashvalue = phone % n ;
	int i = 1, temp = hashvalue;
	while (hashtable[hashvalue].phoneNum != phone && hashtable[hashvalue].phoneNum != 0) {
		if (i % 2 == 1)
			hashvalue = (temp + (i + 1) / 2 * (i + 1) / 2) % n;
		else
			hashvalue = (temp - i / 2 * i / 2) % n;
		i++;
	}
	if (hashtable[hashvalue].phoneNum == 0)
		hashtable[hashvalue].phoneNum = phone;
	hashtable[hashvalue].times++;
	cout << hashvalue << "-----------" << endl;
}

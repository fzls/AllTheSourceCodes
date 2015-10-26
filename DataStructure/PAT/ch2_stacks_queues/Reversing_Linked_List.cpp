/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 Reversing_Linked_List.cpp
* @version:
* @Time: 		 2015-08-27 21:22:37
* @Description:  02-线性结构1. Reversing Linked List (25)
* http://www.patest.cn/contests/mooc-ds/02-%E7%BA%BF%E6%80%A7%E7%BB%93%E6%9E%841
*
+----------------------------------------------------------
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;
struct Node {
	int address;
	int data;
	int next;
};
void swap(Node& node1, Node& node2);

int main() {
	Node nodes[100000];
	int ini_address, n, k;
	cin >> ini_address >> n >> k;
	for (int i = 0; i < n; i++) {
		int address, data, next;
		cin >> address >> data >> next;
		nodes[address].address = address;
		nodes[address].data = data;
		nodes[address].next = next;
	}

	std::vector<Node> list ;
	int address = ini_address;
	while (address != -1) {
		list.push_back(nodes[address]);
		address = nodes[address].next;
	}
	int length = list.size();
	int round = length / k;
	for (int i = 0; i < round; i++) {
		int j, f;
		for (j = i * k, f = (i + 1) * k - 1; j < f; j++, f--)
			swap(list[j], list[f]);
	}
	for (int i = 0; i < length; i++) {
		if (i != length - 1) {
			list[i].next = list[i + 1].address;
		}
		else
			list[i].next = -1;
	}
	for (int i = 0; i < length; i++) {
		if (list[i].next != -1)
			cout << setfill('0') << setw(5)  << list[i].address << " " << list[i].data << " " << setw(5)  << list[i].next << endl << setfill(' ');
		else
			cout << setfill('0') << setw(5) << list[i].address << " " << list[i].data << " " << list[i].next << endl << setfill(' ');

	}

	// cout << endl;
	// system("pause");
	return 0;
}

void swap(Node& node1, Node& node2) {
	Node temp;
	temp = node1;
	node1 = node2;
	node2 = temp;
}

/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 isomorphic_tree.cpp
* @version:
* @Time: 		 2015-09-03 10:08:43
* @Description:  03-树1 树的同构isomorphic    (25分)
*
+----------------------------------------------------------
*/
#include <iostream>
#include <vector>

using namespace std;
struct BinTreeNode
{
	char data;
	char left;
	char right;
	char parent;
	BinTreeNode(): parent('-') {}
	BinTreeNode& operator=(const BinTreeNode& node) {
		data = node.data;
		left = node.left;
		right = node.right;
		return *this;
	}
};

bool check(std::vector<BinTreeNode>& bintree1, std::vector<BinTreeNode>& bintree2, char& node1, char& node2);

int main() {
	std::vector<BinTreeNode> bintree1, bintree2 ;
	BinTreeNode node;
	//initialize
	int n;
	cin >> n;
	bintree1.reserve(n);
	for (int i = 0; i < n; i++)
		bintree1[i].parent = '-';
	for (int i = 0; i < n; i++) {
		cin >> node.data >> node.left >> node.right;
		bintree1[i] = BinTreeNode(node) ;
		// cout << endl << bintree1[i].data << bintree1[i].left << endl;
		if (node.left != '-')
			bintree1[node.left - '0'].parent = '0' + i;
		if (node.right != '-')
			bintree1[node.right - '0'].parent = '0' + i;
	}
	// for (int i = 0; i < n; i++)
	// 	cout << bintree1[i].data << " " << bintree1[i].left << " " << bintree1[i].right << " " << bintree1[i].parent << endl;
	// system("pause");

	int m;
	cin >> m;
	bintree2.reserve(m);
	for (int i = 0; i < m; i++)
		bintree2[i].parent = '-';
	for (int i = 0; i < m; i++) {
		cin >> node.data >> node.left >> node.right;
		bintree2[i] = node;
		if (node.left != '-')
			bintree2[node.left - '0'].parent = '0' + i;
		if (node.right != '-')
			bintree2[node.right - '0'].parent = '0' +  i;
	}
	// for (int i = 0; i < n; i++)
	// 	cout << bintree2[i].data << " " << bintree2[i].left << " " << bintree2[i].right << " " << bintree2[i].parent << endl;
	// system("pause");
	if (m == 0 && n == 0) {
		cout << "Yes" << endl;
	}
	else if (n != m)
		cout << "No" << endl;
	else {
		char root1, root2;
		for (root1 = '0'; bintree1[root1 - '0'].parent != '-' ; root1++);
		for (root2 = '0'; bintree2[root2 - '0'].parent != '-' ; root2++);
		if (check(bintree1, bintree2, root1, root2))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	// cout << endl;
	// system("pause");
	return 0;
}

bool check(std::vector<BinTreeNode>& bintree1, std::vector<BinTreeNode>& bintree2, char& node1, char& node2) {
	bool is_isomorphic = true;
	if (node1 == '-' && node2 == '-')
		return true;
	else if (node1 == '-' || node2 == '-')
		return false;
	// if (bintree1[node1 - '0'].data == '-' && bintree2[node2 - '0'].data == '-') {
	// 	is_isomorphic = true;
	// }

	if (bintree1[node1 - '0'].data == bintree2[node2 - '0'].data ) {
		is_isomorphic = (check(bintree1, bintree2, bintree1[node1 - '0'].left, bintree2[node2 - '0'].left) && check(bintree1, bintree2, bintree1[node1 - '0'].right, bintree2[node2 - '0'].right)) || (check(bintree1, bintree2, bintree1[node1 - '0'].left, bintree2[node2 - '0'].right) && check(bintree1, bintree2, bintree1[node1 - '0'].right, bintree2[node2 - '0'].left));
	}
	else
		is_isomorphic = false;


	return is_isomorphic;

}

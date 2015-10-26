/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 list_leaves.cpp
* @version:
* @Time: 		 2015-09-03 14:26:42
* @Description:  03-树2 List Leaves   (25分)
*
+----------------------------------------------------------
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
struct BinTreeNode
{
	int data;
	char left;
	char right;
	char parent;
};

void level_travesal_and_print_leaves(vector<BinTreeNode>& tree, char root);

int main() {
	int n;
	cin >> n;
	std::vector<BinTreeNode> tree ;
	//initialize
	tree.reserve(n);
	for (int i = 0; i < n; i++) {
		tree[i].parent = '-';
	}
	for (int i = 0; i < n; i++) {
		tree[i].data = i;
		cin >> tree[i].left >> tree[i].right;
		if (tree[i].left != '-')
			tree[tree[i].left - '0'].parent = '0' + i;
		if (tree[i].right != '-')
			tree[tree[i].right - '0'].parent = '0' + i;
	}

	// for (int i = 0; i < n; i++)
	// 	cout << tree[i].data << " " << tree[i].left << " " << tree[i].right << " " << tree[i].parent << endl;

	//level travesal and output the leaves
	char root;
	for (root = '0'; tree[root - '0'].parent != '-'; root++);
	if (root > '9')
		cout << "there is no root , the input tree is wrong" << endl;
	else {
		level_travesal_and_print_leaves(tree, root);
	}



	// cout << endl;
	// system("pause");
	return 0;
}

void level_travesal_and_print_leaves(vector<BinTreeNode>& tree, char root) {
	queue<BinTreeNode> level_que;
	BinTreeNode top;
	if (root != '-') {
		level_que.push(tree[root - '0']);
		while (!level_que.empty()) {
			top = level_que.front();
			level_que.pop();
			if (top.left != '-')
				level_que.push(tree[top.left - '0']);
			if (top.right != '-')
				level_que.push(tree[top.right - '0']);
			if (top.left == '-' && top.right == '-') {
				cout << top.data;
				if (!level_que.empty())
					cout << " ";
			}
		}
		cout << endl;
	}
	else { //if tree is empty

	}
}

/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 Complete_Binary_Search_Tree.cpp
* @version:
* @Time: 		 2015-09-05 12:38:32
* @Description: 04-树6 Complete Binary Search Tree   (30分)
*
+----------------------------------------------------------
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;
static int counter;
struct CbstNode
{
	int data;
	CbstNode* left;
	CbstNode* right;
};

void creatCompleteBST(CbstNode* &root, vector<int>& bst, int left, int right);
void preorder(CbstNode* root);
void level_order(CbstNode* root);
int main() {
	int n, data;
	cin >> n;
	std::vector<int> bst ;
	CbstNode* root = 0;
	for (int i = 0; i < n; i++) {
		cin >> data;
		bst.push_back(data);
	}
	sort(bst.begin(), bst.end());
	creatCompleteBST(root, bst, 0, n - 1);
	counter = n;
	// preorder(root);
	level_order(root);

	// cout << endl;
	// system("pause");
	return 0;
}
void creatCompleteBST(CbstNode* &root, vector<int>& bst, int left, int right) {
	int root_index = 0;
	int n = right - left + 1 ;
	int k = (int)log2(n) + 1;
	if (n > 0) {
		if (n + 1 <= 3 * (int)pow(2, k - 2))
			root_index = n - (int)pow(2, k - 2) + left;
		else
			root_index = (int)pow(2, k - 1) - 1 + left;

		CbstNode* node = new CbstNode;
		node->data = bst[root_index];
		node->left = 0;
		node->right = 0;
		root = node;

		creatCompleteBST(root->left, bst, left, root_index - 1);
		creatCompleteBST(root->right, bst, root_index + 1, right);

	}
}

void preorder(CbstNode* root) {
	if (root) {
		cout << root->data << ends;
		preorder(root->left);
		preorder(root->right);
	}
}
void level_order(CbstNode* root) {
	queue<CbstNode*> level;
	if (root) {
		level.push(root);
		while (!level.empty()) {
			root = level.front();
			level.pop();
			cout << root->data << (counter == 1 ? "" : " ");
			--counter;
			if (root->left)
				level.push(root->left);
			if (root->right)
				level.push(root->right);
		}
	}
}

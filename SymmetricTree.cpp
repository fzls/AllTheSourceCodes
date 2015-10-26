/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 SymmetricTree.cpp
* @version:
* @Time: 		 2015-10-24 15:09:03
* @Description:
*
+----------------------------------------------------------
*/
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == NULL)
			return true;
		else
			return isSymmetric(root->left, root->right);
	}
	bool isSymmetric(TreeNode* r1, TreeNode* r2) {
		if (r1 == NULL && r2 == NULL)
			return true;
		else if (r1 == NULL || r2 == NULL)
			return false;
		else if (r1->val != r2->val)
			return false;
		else
			return isSymmetric(r1->left, r2->right) && isSymmetric(r2->left, r1->right);
	}
	bool isSymmetric(TreeNode* root) {
		if (root == NULL)
			return true;
		else {
			TreeNode* r1 = root->left;
			TreeNode* r2 = root->right;
			std::stack<TreeNode*> s1, s2;
			s1.push(r1);
			s2.push(r2);
			while (!s1.empty() && !s2.empty()) {
				r1 = s1.top(); s1.pop();
				r2 = s2.top(); s2.pop();
				if (!check_both_null_or_equal(r1, r2))
					return false;
				else if (r1 != NULL) {
					s1.push(r1->left);
					s2.push(r2->right);
					s1.push(r1->right);
					s2.push(r2->left);
				}
			}
			if (s1.empty() && s2.empty())
				return true;
			else
				return false;
		}


	}
	bool check_both_null_or_equal(TreeNode * r1, TreeNode * r2) {
		if (r1 == NULL && r2 == NULL)
			return true;
		else if (r1 == NULL || r2 == NULL)
			return false;
		else if (r1->val == r2->val)
			return true;
		else
			return false;
	}

};


int main() {
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);


	cout << endl;
	system("pause");
	return 0;
}


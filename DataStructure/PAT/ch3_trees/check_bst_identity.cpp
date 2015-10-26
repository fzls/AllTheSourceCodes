/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 check_bst_identity.cpp
* @version:
* @Time: 		 2015-09-04 15:04:34
* @Description:  04-树4 是否同一棵二叉搜索树   (25分)
* 对每一组需要检查的序列，如果其生成的二叉搜索树跟对应的初始序列生成的一样，输出“Yes”，否则输出“No”。
* just reconstruct the binry search tree would be fine
*
+----------------------------------------------------------
*/
#include <vector>
#include <iostream>

using namespace std;
struct BinTreeNode
{
	int data;
	BinTreeNode* left;
	BinTreeNode* right;
};
typedef BinTreeNode* BinTree;

void creatBinTree(BinTree& root, int node_numbers);
bool check_bst_identity(BinTree& original, BinTree& test);
void insert(BinTree& root, int data);
// void preorder(BinTree& root) {
// 	if (root) {
// 		cout << root->data << ends;
// 		preorder(root->left);
// 		preorder(root->right);
// 	}
// }
//
// int getHeight(BinTree& root) {
// 	if (root == 0)
// 		return 0;
// 	else {
// 		int h1, h2;
// 		h1 = getHeight(root->left);
// 		h2 = getHeight(root->right);
// 		return (h1 > h2 ? h1 : h2) + 1;
// 	}
// }

int main()
{
	// freopen("test.in", "r", stdin);
	// freopen("test.out", "w", stdout);
	int n, l;
	cin >> n;
	while (n != 0) {
		cin >> l;
		BinTree root_original = 0;
		creatBinTree(root_original, n);
		// preorder(root_original);
		// cout << endl;
		// cout << getHeight(root_original);
		for (int i = 0; i < l; i++) {
			BinTree root_test = 0;
			creatBinTree(root_test, n);
			// preorder(root_test);
			// cout << endl;
			// cout << getHeight(root_test);
			if (check_bst_identity(root_original, root_test))
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}

		cin >> n;
	}

	return 0;
}

void insert(BinTree& root, int data) {
	if (root == 0) {
		BinTree node = new BinTreeNode;
		node->data = data;
		node->left = 0;
		node->right = 0;
		root = node;//dont forget this step
	}
	else if (data < root->data) {
		insert(root->left, data);
	}
	else if (data > root->data) {
		insert(root->right, data);
	}
}


void creatBinTree(BinTree& root, int node_numbers) {
	int data;
	for (int i = 0; i < node_numbers; i++) {
		cin >> data;
		insert(root, data);
	}
}

bool check_bst_identity(BinTree& original, BinTree& test) {
	if (original == 0 && test == 0)
		return true;
	else if (original == 0 || test == 0)
		return false;
	else {
		if (original->data == test->data)
			return check_bst_identity(original->left, test->left) && check_bst_identity(original->right, test->right);
		else
			return false;
	}
}




// //version 1.0   not reconstruct the bst
// #include <iostream>
// #include <vector>

// using namespace std;

// bool check(vector<int>& original, vector<int>& totest );
// bool check(vector<int>& original, vector<int>& totest, vector<int>::iterator ori, vector<int>::iterator test , int original_lower_limit, int original_upper_limit, int totest_lower_limit,  int totest_upper_limit);

// int main() {
// 	int n, l, number;
// 	cin >> n;
// 	while (n != 0) {
// 		cin >> l;
// 		std::vector<int> original ;
// 		for (int i = 0; i < n; i++) {
// 			cin >> number;
// 			original.push_back(number);
// 		}

// 		for (int i = 0; i < l; i++) {
// 			std::vector<int> totest ;
// 			// totest.clear();
// 			for (int j = 0; j < n; j++) {
// 				cin >> number;
// 				totest.push_back(number);
// 			}

// 			if (check(original, totest))
// 				cout << "Yes" << endl;
// 			else
// 				cout << "No" << endl;
// 		}

// 		cin >> n;
// 	}

// 	// cout << endl;
// 	// system("pause");
// 	return 0;
// }
// bool check(vector<int>& original, vector<int>& totest ) {
// 	return  check(original, totest, original.begin(), totest.begin(), 1, original.size(), 1, totest.size()) ;
// }
// //upper and lower limit can  be accessed
// bool check(vector<int>& original, vector<int>& totest, vector<int>::iterator ori, vector<int>::iterator test , int original_lower_limit, int original_upper_limit, int totest_lower_limit,  int totest_upper_limit) {
// 	if (ori == original.end() && test == totest.end())
// 		return true;
// 	else if (ori != original.end() && test == totest.end() || ori == original.end() && test != totest.end())
// 		return false;
// 	else if (*ori != *test)
// 		return false;
// 	else {
// 		int temp;
// 		vector<int>::iterator temp_ori = ori, temp_test = test;
// 		// check LEFT
// 		temp = *ori;
// 		for (++ori; ori != original.end() && !(*ori < temp && *ori >= original_lower_limit && *ori <= original_upper_limit); ++ori);

// 		temp = *test;
// 		for (++test; test != totest.end() && !(*test < temp && *test >= totest_lower_limit && *test <= totest_upper_limit); ++test);

// //remaing
// 		if (!check(original, totest, ori, test, original_lower_limit, *temp_ori, totest_lower_limit, *temp_test))
// 			return false ;
// 		else { //check RIGHT
// 			ori = temp_ori;
// 			test = temp_test;

// 			temp = *ori;
// 			for (++ori; ori != original.end() && !(*ori > temp && *ori >= original_lower_limit && *ori <= original_upper_limit); ++ori);

// 			temp = *test;
// 			for (++test; test != totest.end() && !(*test > temp && *test >= totest_lower_limit && *test <= totest_upper_limit); ++test);

// 			if (!check(original, totest, ori, test,  *temp_ori, original_upper_limit,  *temp_test, totest_upper_limit))
// 				return false;
// 			return true;
// 		}
// 	}
// }


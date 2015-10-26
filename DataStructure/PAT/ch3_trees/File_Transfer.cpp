/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 File_Transfer.cpp
* @version:
* @Time: 		 2015-09-05 15:34:11
* @Description:  05-树8 File Transfer   (25分)
* 	first I try to use the tree to represent set, and there is some effciency problem in merge two
* bst tree and banlance trees after insert new elements.
* 	second I give up trees and turn to vector, however alothough passed the test, it is still low in
* efficiency due to the sort operation needed if I want to use binary search or merge algorithm
* offered in the STL.
* 	and after reading the data structure text book writen by chenyue , I found that we can use subindex to
* represent the elements and the value to represent it is the root of a set if it is minus or it's value is
* the root of set which it belonged to. and thus the merge and find can be done in O(1) time.
*
*
+----------------------------------------------------------
*/
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
void input(vector<vector<int>> &components, int &index, int &counter);
void check(vector<vector<int>> &components, int &index);
void stop(int index, int counter, int total_pc);
bool find_in_vector(vector<int>::iterator first, vector<int>::iterator last, int data);
int main() {
	int n;
	cin >> n;
	std::vector<std::vector<int>> components ;
	components.reserve(n);
	char cmd;
	int index = -1, counter = 0;
	bool terminate = false;
	while (cin >> cmd) {
		switch (cmd) {
		case 'I' : input(components, index, counter) ; break;
		case 'C' : check(components, index) ; break;
		case 'S' : stop(index, counter, n) ; terminate = true; break;
		}
		if (terminate)
			break;
	}

	// cout << endl;
	// system("pause");

}

void input(vector<vector<int>> &components, int &index, int &counter) {
	int pc1, pc2;
	cin >> pc1 >> pc2;
	int index_pc1 = -1, index_pc2 = -1;
	for (int i = 0; i <= index; i++)
		if (find_in_vector(components[i].begin(), components[i].end(), pc1)) {
			index_pc1 = i;
			break;
		}
	for (int i = 0; i <= index; i++)
		if (find_in_vector(components[i].begin(), components[i].end(), pc2)) {
			index_pc2 = i;
			break;
		}

	if (index_pc1 == -1 && index_pc2 == -1) {
		++index;
		components[index].push_back(pc1);
		components[index].push_back(pc2);
		// sort(components[index].begin(), components[index].end());
		counter += 2;
	}
	else if (index_pc1 != -1 && index_pc2 == -1) {
		components[index_pc1].push_back(pc2);
		// sort(components[index_pc1].begin(), components[index_pc1].end());
		counter++;
	}
	else if (index_pc1 == -1 && index_pc2 != -1) {
		components[index_pc2].push_back(pc1);
		// sort(components[index_pc2].begin(), components[index_pc2].end());
		counter++;
	}
	else if (index_pc1 != -1 && index_pc2 != -1 && index_pc1 != index_pc2) {
		if (index_pc1 > index_pc2)
			swap(index_pc1, index_pc2);
		vector<int> temp(components[index_pc1].size() + components[index_pc2].size());
		sort(components[index_pc1].begin(), components[index_pc1].end());
		sort(components[index_pc2].begin(), components[index_pc2].end());
		merge(components[index_pc1].begin() , components[index_pc1].end(), components[index_pc2].begin(), components[index_pc2].end(), temp.begin() );
		components[index_pc1] = temp;

		for (int i = index_pc2; i < index; i++)
			components[i] = components[i + 1];
		components[index].clear();
		index--;
	}
}
void check(vector<vector<int>> &components, int &index) {
	int pc1, pc2, i;
	cin >> pc1 >> pc2;
	for (i = 0; i <= index; i++) {
		if (find_in_vector(components[i].begin(), components[i].end(), pc1) && find_in_vector(components[i].begin(), components[i].end(), pc2)) {
			cout << "yes" << endl;
			break;
		}
	}
	if (i > index)
		cout << "no" << endl;
}
void stop(int index, int counter, int total_pc) {
	if (index == 0 && counter == total_pc)
		cout << "The network is connected." << endl;
	else
		cout << "There are " << index + 1 + total_pc - counter << " components." << endl;
}
bool find_in_vector(vector<int>::iterator first, vector<int>::iterator last, int data) {
	bool found = false;
	for (auto i = first; i != last; ++i)
		if (*i == data) {
			found = true;
			break;
		}
	return found;
}






////avl_tree style version
// #include <iostream>
// #include <vector>

// using namespace std;

// struct AVL_Tree_Node
// {
// 	int data;
// 	AVL_Tree_Node* left;
// 	AVL_Tree_Node* right;
// };

// void input(vector<AVL_Tree_Node*>& roots, int &index, int& counter);
// void check(vector<AVL_Tree_Node*>& roots, int &index);
// void stop(int index, int counter, int total_pc);
// // bool find(AVL_Tree_Node* root, int data);
// void insert(AVL_Tree_Node* &root, int data);
// void merge_tree(AVL_Tree_Node* &root1, AVL_Tree_Node* &root2);//需要改进以实现合并后仍未二叉搜索树
// void delete_bst(AVL_Tree_Node* &root);
// bool bin_find(AVL_Tree_Node* root, int data);
// void LLRotate(AVL_Tree_Node* &root);
// void LRRotate(AVL_Tree_Node* &root);
// void RRRotate(AVL_Tree_Node* &root);
// void RLRotate(AVL_Tree_Node* &root);
// int getHeight(AVL_Tree_Node* root);


// void BinTree2Vector(AVL_Tree_Node* root, vector<int> &path);
// void merge_vector(vector<int> &path1, vector<int> &path2);
// AVL_Tree_Node* Vector2BinTree(AVL_Tree_Node* &root, vector<int> &path, int left, int right);


// int main() {
// 	std::vector<AVL_Tree_Node*> roots ;
// 	int n;
// 	cin >> n;
// 	roots.reserve(n);
// 	for (int i = 0; i < n; i++)
// 		roots[i] = 0;
// 	int index = -1, counter = 0;
// 	char cmd;
// 	bool terminate = false;
// 	while (cin >> cmd) {
// 		switch (cmd) {
// 		case 'I' : input(roots, index, counter) ; break;
// 		case 'C' : check(roots, index) ; break;
// 		case 'S' : stop(index, counter, n) ; terminate = true; break;
// 		}
// 		if (terminate)
// 			break;
// 	}
// 	for (int i = 0; i <= index; i++)
// 		delete_bst(roots[i]);
// 	// cout << endl;
// 	// system("pause");
// 	return 0;
// }

// void input(vector<AVL_Tree_Node*>& roots, int &index, int& counter) {
// 	int pc1, pc2;
// 	cin >> pc1 >> pc2;
// 	int index_pc1 = -1, index_pc2 = -1;
// 	for (int i = 0; i <= index; i++)
// 		if (bin_find(roots[i], pc1)) {
// 			index_pc1 = i;
// 			break;
// 		}
// 	for (int i = 0; i <= index; i++)
// 		if (bin_find(roots[i], pc2)) {
// 			index_pc2 = i;
// 			break;
// 		}

// 	if (index_pc1 == -1 && index_pc2 == -1) {
// 		++index;
// 		insert(roots[index], pc1);
// 		insert(roots[index], pc2);
// 		counter += 2;
// 	}
// 	else if (index_pc1 != -1 && index_pc2 == -1) {
// 		insert(roots[index_pc1], pc2);
// 		counter++;
// 	}
// 	else if (index_pc1 == -1 && index_pc2 != -1) {
// 		insert(roots[index_pc2], pc1);
// 		counter++;
// 	}
// 	else if (index_pc1 != -1 && index_pc2 != -1 && index_pc1 != index_pc2) {
// 		if (index_pc1 > index_pc2)
// 			swap(index_pc1, index_pc2);
// 		merge_tree(roots[index_pc1], roots[index_pc2]);

// 		for (int i = index_pc2; i < index; i++)
// 			roots[i] = roots[i + 1];
// 		roots[index] = 0;
// 		index--;
// 	}


// }
// void check(vector<AVL_Tree_Node*>& roots, int &index) {
// 	int pc1, pc2;
// 	cin >> pc1 >> pc2;
// 	int i;
// 	for ( i = 0; i <= index; i++) {
// 		if (bin_find(roots[i], pc1) && bin_find(roots[i], pc2)) {
// 			cout << "yes" << endl;
// 			break;
// 		}
// 	}
// 	if (i > index)
// 		cout << "no" << endl;
// }
// void stop(int index, int counter, int total_pc) {
// 	if (index == 0 && counter == total_pc)
// 		cout << "The network is connected." << endl;
// 	else
// 		cout << "There are " << index + 1 + total_pc - counter << " components." << endl;
// }
// bool bin_find(AVL_Tree_Node* root, int data) {
// 	if (root) {
// 		if (data == root->data)
// 			return true;
// 		else if (data < root->data)
// 			return bin_find(root->left, data);
// 		else
// 			return bin_find(root->right, data);
// 	}
// 	else
// 		return false;
// }


// // bool find(AVL_Tree_Node* root, int data) {
// // 	if (bin_find(root, data))
// // 		return true;
// // 	else if (root) {
// // 		if (data == root->data)
// // 			return true;
// // 		else
// // 			return find(root->left, data) || find(root->right, data);
// // 	}
// // 	else
// // 		return false;
// // }

// // void insert(AVL_Tree_Node* &root, int data) {
// // 	if (root == 0) {
// // 		AVL_Tree_Node* node = new AVL_Tree_Node;
// // 		node->data = data;
// // 		node->left = 0;
// // 		node->right = 0;
// // 		root = node;
// // 	}
// // 	else if (data < root->data)
// // 		insert(root->left, data);
// // 	else if (data > root->data)
// // 		insert(root->right, data);
// // }

// void insert(AVL_Tree_Node* &root, int data) {
// 	if (root == 0) {//create new node
// 		AVL_Tree_Node* node = new AVL_Tree_Node;
// 		node->data = data;
// 		node->left = 0;
// 		node->right = 0;
// 		root = node;
// 	}
// 	else {
// 		if (data < root->data) {//insert left
// 			insert(root->left, data);
// 			if (getHeight(root->left) - getHeight(root->right) == 2) {//if after insert, not balanced
// 				if (data < root->left->data) {
// 					LLRotate(root);
// 				}
// 				else if (data > root->left->data) {
// 					LRRotate(root);
// 				}
// 			}
// 		}
// 		else if (data > root->data) {
// 			insert(root->right, data);
// 			if (getHeight(root->left) - getHeight(root->right) == -2) {
// 				if (data > root->right->data) {
// 					RRRotate(root);
// 				}
// 				else if (data < root->right->data) {
// 					RLRotate(root);
// 				}
// 			}
// 		}
// 	}
// }


// void merge_tree(AVL_Tree_Node* &root1, AVL_Tree_Node* &root2) {
// 	// AVL_Tree_Node* temp2 = new AVL_Tree_Node;
// 	// AVL_Tree_Node* temp;
// 	// temp2 = root2;
// 	// temp = root1;
// 	// while (temp->right != 0)
// 	// 	temp = temp->right;
// 	// temp->right = temp2;
// 	std::vector<int> path1, path2, path3;

// 	BinTree2Vector(root1, path1); //wait
// 	BinTree2Vector(root2, path2);
// 	merge_vector(path1, path2);
// 	delete_bst(root1);
// 	delete_bst(root2);
// 	AVL_Tree_Node* root = 0;
// 	root1 = Vector2BinTree(root, path1, 0, static_cast<int>(path1.size()) - 1);

// }
// void delete_bst(AVL_Tree_Node* &root) {
// 	if (root) {
// 		delete_bst(root->left);
// 		delete_bst(root->right);
// 		delete(root);
// 	}
// }

// void BinTree2Vector(AVL_Tree_Node* root, vector<int> &path) {
// 	if (root) {
// 		BinTree2Vector(root->left, path);
// 		path.push_back(root->data);
// 		BinTree2Vector(root->right, path);
// 	}
// }
// void merge_vector(vector<int> &path1, vector<int> &path2) {
// 	auto first = path1.begin();
// 	auto second = path2.begin();
// 	std::vector<int> path3 ;

// 	while (first != path1.end() && second != path2.end()) {
// 		if (*first < *second)
// 			path3.push_back(*first++);
// 		else
// 			path3.push_back(*second++);
// 	}
// 	while (first != path1.end()) {
// 		path3.push_back(*first++);
// 	}
// 	while (second != path2.end()) {
// 		path3.push_back(*second++);
// 	}
// 	path1 = path3;

// }
// AVL_Tree_Node* Vector2BinTree(AVL_Tree_Node* &root, vector<int> &path, int left, int right) {
// 	if (left <= right) {
// 		int mid = left + (right - left) / 2;
// 		root = new AVL_Tree_Node;
// 		root->data = path[mid];
// 		Vector2BinTree(root->left, path, left, mid - 1);
// 		Vector2BinTree(root->right, path, mid + 1, right);
// 	}
// 	return root;
// }
// int getHeight(AVL_Tree_Node* root) {
// 	if (root == 0)
// 		return 0;
// 	else {
// 		int height_l = getHeight(root->left);
// 		int height_r = getHeight(root->right);
// 		return (height_l > height_r ? height_l : height_r) + 1;
// 	}
// }

// void LLRotate(AVL_Tree_Node* &root) {
// 	AVL_Tree_Node* temp = root->left;
// 	root->left = temp->right;
// 	temp->right = root;

// 	root = temp;
// }
// void LRRotate(AVL_Tree_Node* &root) {
// 	RRRotate(root->left);
// 	LLRotate(root);
// }
// void RRRotate(AVL_Tree_Node* &root) {
// 	AVL_Tree_Node* temp = root->right;
// 	root->right = temp->left;
// 	temp -> left = root;

// 	root = temp;
// }
// void RLRotate(AVL_Tree_Node* &root) {
// 	LLRotate(root->right);
// 	return RRRotate(root);
// }


// // binary tree version
// #include <iostream>
// #include <vector>

// using namespace std;

// struct BinTreeNode
// {
// 	int data;
// 	BinTreeNode* left;
// 	BinTreeNode* right;
// };

// void input(vector<BinTreeNode*>& roots, int &index, int& counter);
// void check(vector<BinTreeNode*>& roots, int &index);
// void stop(int index, int counter, int total_pc);
// bool find(BinTreeNode* root, int data);
// void insert(BinTreeNode* &root, int data);
// void merge_tree(BinTreeNode* &root1, BinTreeNode* &root2);//需要改进以实现合并后仍未二叉搜索树
// void delete_bst(BinTreeNode* &root);
// bool bin_find(BinTreeNode* root, int data);
// int main() {
// 	std::vector<BinTreeNode*> roots ;
// 	int n;
// 	cin >> n;
// 	roots.reserve(n);
// 	for (int i = 0; i < n; i++)
// 		roots[i] = 0;
// 	int index = -1, counter = 0;
// 	char cmd;
// 	bool terminate = false;
// 	while (cin >> cmd) {
// 		switch (cmd) {
// 		case 'I' : input(roots, index, counter) ; break;
// 		case 'C' : check(roots, index) ; break;
// 		case 'S' : stop(index, counter, n) ; terminate = true; break;
// 		}
// 		if (terminate)
// 			break;
// 	}
// 	for (int i = 0; i <= index; i++)
// 		delete_bst(roots[i]);
// 	// cout << endl;
// 	// system("pause");
// 	return 0;
// }

// void input(vector<BinTreeNode*>& roots, int &index, int& counter) {
// 	int pc1, pc2;
// 	cin >> pc1 >> pc2;
// 	int index_pc1 = -1, index_pc2 = -1;
// 	for (int i = 0; i <= index; i++)
// 		if (find(roots[i], pc1)) {
// 			index_pc1 = i;
// 			break;
// 		}
// 	for (int i = 0; i <= index; i++)
// 		if (find(roots[i], pc2)) {
// 			index_pc2 = i;
// 			break;
// 		}

// 	if (index_pc1 == -1 && index_pc2 == -1) {
// 		++index;
// 		insert(roots[index], pc1);
// 		insert(roots[index], pc2);
// 		counter += 2;
// 	}
// 	else if (index_pc1 != -1 && index_pc2 == -1) {
// 		insert(roots[index_pc1], pc2);
// 		counter++;
// 	}
// 	else if (index_pc1 == -1 && index_pc2 != -1) {
// 		insert(roots[index_pc2], pc1);
// 		counter++;
// 	}
// 	else if (index_pc1 != -1 && index_pc2 != -1 && index_pc1 != index_pc2) {
// 		if (index_pc1 > index_pc2)
// 			swap(index_pc1, index_pc2);
// 		merge_tree(roots[index_pc1], roots[index_pc2]);

// 		for (int i = index_pc2; i < index; i++)
// 			roots[i] = roots[i + 1];
// 		roots[index] = 0;
// 		index--;
// 	}


// }
// void check(vector<BinTreeNode*>& roots, int &index) {
// 	int pc1, pc2;
// 	cin >> pc1 >> pc2;
// 	int i;
// 	for ( i = 0; i <= index; i++) {
// 		if (find(roots[i], pc1) && find(roots[i], pc2)) {
// 			cout << "yes" << endl;
// 			break;
// 		}
// 	}
// 	if (i > index)
// 		cout << "no" << endl;
// }
// void stop(int index, int counter, int total_pc) {
// 	if (index == 0 && counter == total_pc)
// 		cout << "The network is connected." << endl;
// 	else
// 		cout << "There are " << index + 1 + total_pc - counter << " components." << endl;
// }
// bool bin_find(BinTreeNode* root, int data) {
// 	if (root) {
// 		if (data == root->data)
// 			return true;
// 		else if (data < root->data)
// 			return bin_find(root->left, data);
// 		else
// 			return bin_find(root->right, data);
// 	}
// 	else
// 		return false;
// }


// bool find(BinTreeNode* root, int data) {
// 	if (bin_find(root, data))
// 		return true;
// 	else if (root) {
// 		if (data == root->data)
// 			return true;
// 		else
// 			return find(root->left, data) || find(root->right, data);
// 	}
// 	else
// 		return false;
// }

// void insert(BinTreeNode* &root, int data) {
// 	if (root == 0) {
// 		BinTreeNode* node = new BinTreeNode;
// 		node->data = data;
// 		node->left = 0;
// 		node->right = 0;
// 		root = node;
// 	}
// 	else if (data < root->data)
// 		insert(root->left, data);
// 	else if (data > root->data)
// 		insert(root->right, data);
// }
// void merge_tree(BinTreeNode* &root1, BinTreeNode* &root2) {
// 	BinTreeNode* temp2 = new BinTreeNode;
// 	BinTreeNode* temp;
// 	temp2 = root2;
// 	temp = root1;
// 	while (temp->right != 0)
// 		temp = temp->right;
// 	temp->right = temp2;
// }
// void delete_bst(BinTreeNode* &root) {
// 	if (root) {
// 		delete_bst(root->left);
// 		delete_bst(root->right);
// 		delete(root);
// 	}
// }



// //binary tree hebing version


// #include <iostream>
// #include <vector>

// using namespace std;

// struct BinTreeNode
// {
// 	int data;
// 	BinTreeNode* left;
// 	BinTreeNode* right;
// };

// void input(vector<BinTreeNode*>& roots, int &index, int& counter);
// void check(vector<BinTreeNode*>& roots, int &index);
// void stop(int index, int counter, int total_pc);
// // bool find(BinTreeNode* root, int data);
// void insert(BinTreeNode* &root, int data);
// void merge_tree(BinTreeNode* &root1, BinTreeNode* &root2);//需要改进以实现合并后仍未二叉搜索树
// void delete_bst(BinTreeNode* &root);
// bool bin_find(BinTreeNode* root, int data);



// void BinTree2Vector(BinTreeNode* root, vector<int> &path);
// void merge_vector(vector<int> &path1, vector<int> &path2);
// BinTreeNode* Vector2BinTree(BinTreeNode* &root, vector<int> &path, int left, int right);


// int main() {
// 	std::vector<BinTreeNode*> roots ;
// 	int n;
// 	cin >> n;
// 	roots.reserve(n);
// 	for (int i = 0; i < n; i++)
// 		roots[i] = 0;
// 	int index = -1, counter = 0;
// 	char cmd;
// 	bool terminate = false;
// 	while (cin >> cmd) {
// 		switch (cmd) {
// 		case 'I' : input(roots, index, counter) ; break;
// 		case 'C' : check(roots, index) ; break;
// 		case 'S' : stop(index, counter, n) ; terminate = true; break;
// 		}
// 		if (terminate)
// 			break;
// 	}
// 	for (int i = 0; i <= index; i++)
// 		delete_bst(roots[i]);
// 	// cout << endl;
// 	// system("pause");
// 	return 0;
// }

// void input(vector<BinTreeNode*>& roots, int &index, int& counter) {
// 	int pc1, pc2;
// 	cin >> pc1 >> pc2;
// 	int index_pc1 = -1, index_pc2 = -1;
// 	for (int i = 0; i <= index; i++)
// 		if (bin_find(roots[i], pc1)) {
// 			index_pc1 = i;
// 			break;
// 		}
// 	for (int i = 0; i <= index; i++)
// 		if (bin_find(roots[i], pc2)) {
// 			index_pc2 = i;
// 			break;
// 		}

// 	if (index_pc1 == -1 && index_pc2 == -1) {
// 		++index;
// 		insert(roots[index], pc1);
// 		insert(roots[index], pc2);
// 		counter += 2;
// 	}
// 	else if (index_pc1 != -1 && index_pc2 == -1) {
// 		insert(roots[index_pc1], pc2);
// 		counter++;
// 	}
// 	else if (index_pc1 == -1 && index_pc2 != -1) {
// 		insert(roots[index_pc2], pc1);
// 		counter++;
// 	}
// 	else if (index_pc1 != -1 && index_pc2 != -1 && index_pc1 != index_pc2) {
// 		if (index_pc1 > index_pc2)
// 			swap(index_pc1, index_pc2);
// 		merge_tree(roots[index_pc1], roots[index_pc2]);

// 		for (int i = index_pc2; i < index; i++)
// 			roots[i] = roots[i + 1];
// 		roots[index] = 0;
// 		index--;
// 	}


// }
// void check(vector<BinTreeNode*>& roots, int &index) {
// 	int pc1, pc2;
// 	cin >> pc1 >> pc2;
// 	int i;
// 	for ( i = 0; i <= index; i++) {
// 		if (bin_find(roots[i], pc1) && bin_find(roots[i], pc2)) {
// 			cout << "yes" << endl;
// 			break;
// 		}
// 	}
// 	if (i > index)
// 		cout << "no" << endl;
// }
// void stop(int index, int counter, int total_pc) {
// 	if (index == 0 && counter == total_pc)
// 		cout << "The network is connected." << endl;
// 	else
// 		cout << "There are " << index + 1 + total_pc - counter << " components." << endl;
// }
// bool bin_find(BinTreeNode* root, int data) {
// 	if (root) {
// 		if (data == root->data)
// 			return true;
// 		else if (data < root->data)
// 			return bin_find(root->left, data);
// 		else
// 			return bin_find(root->right, data);
// 	}
// 	else
// 		return false;
// }


// // bool find(BinTreeNode* root, int data) {
// // 	if (bin_find(root, data))
// // 		return true;
// // 	else if (root) {
// // 		if (data == root->data)
// // 			return true;
// // 		else
// // 			return find(root->left, data) || find(root->right, data);
// // 	}
// // 	else
// // 		return false;
// // }

// void insert(BinTreeNode* &root, int data) {
// 	if (root == 0) {
// 		BinTreeNode* node = new BinTreeNode;
// 		node->data = data;
// 		node->left = 0;
// 		node->right = 0;
// 		root = node;
// 	}
// 	else if (data < root->data)
// 		insert(root->left, data);
// 	else if (data > root->data)
// 		insert(root->right, data);
// }


// void merge_tree(BinTreeNode* &root1, BinTreeNode* &root2) {
// 	// BinTreeNode* temp2 = new BinTreeNode;
// 	// BinTreeNode* temp;
// 	// temp2 = root2;
// 	// temp = root1;
// 	// while (temp->right != 0)
// 	// 	temp = temp->right;
// 	// temp->right = temp2;
// 	std::vector<int> path1, path2, path3;

// 	BinTree2Vector(root1, path1); //wait
// 	BinTree2Vector(root2, path2);
// 	merge_vector(path1, path2);
// 	delete_bst(root1);
// 	delete_bst(root2);
// 	BinTreeNode* root = 0;
// 	root1 = Vector2BinTree(root, path1, 0, static_cast<int>(path1.size()) - 1);

// }
// void delete_bst(BinTreeNode* &root) {
// 	if (root) {
// 		delete_bst(root->left);
// 		delete_bst(root->right);
// 		delete(root);
// 	}
// }

// void BinTree2Vector(BinTreeNode* root, vector<int> &path) {
// 	if (root) {
// 		BinTree2Vector(root->left, path);
// 		path.push_back(root->data);
// 		BinTree2Vector(root->right, path);
// 	}
// }
// void merge_vector(vector<int> &path1, vector<int> &path2) {
// 	auto first = path1.begin();
// 	auto second = path2.begin();
// 	std::vector<int> path3 ;

// 	while (first != path1.end() && second != path2.end()) {
// 		if (*first < *second)
// 			path3.push_back(*first++);
// 		else
// 			path3.push_back(*second++);
// 	}
// 	while (first != path1.end()) {
// 		path3.push_back(*first++);
// 	}
// 	while (second != path2.end()) {
// 		path3.push_back(*second++);
// 	}
// 	path1 = path3;

// }
// BinTreeNode* Vector2BinTree(BinTreeNode* &root, vector<int> &path, int left, int right) {
// 	if (left <= right) {
// 		int mid = left + (right - left) / 2;
// 		root = new BinTreeNode;
// 		root->data = path[mid];
// 		Vector2BinTree(root->left, path, left, mid - 1);
// 		Vector2BinTree(root->right, path, mid + 1, right);
// 	}
// 	return root;
// }

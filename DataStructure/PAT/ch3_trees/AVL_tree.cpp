/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 AVL_tree.cpp
* @version:
* @Time: 		 2015-09-04 19:21:19
* @Description:  04-树5 Root of AVL Tree   (25分)
*
+----------------------------------------------------------
*/
//c++ stytle
#include <iostream>

using namespace std;

struct AVL_Tree_Node
{
	int data;
	AVL_Tree_Node* left;
	AVL_Tree_Node* right;
	AVL_Tree_Node(int d = 0, AVL_Tree_Node* l = 0, AVL_Tree_Node* r = 0): data(d), left(l), right(r) {}
};

void insert(AVL_Tree_Node* &root, int data);
void LLRotate(AVL_Tree_Node* &root);
void LRRotate(AVL_Tree_Node* &root);
void RRRotate(AVL_Tree_Node* &root);
void RLRotate(AVL_Tree_Node* &root);
void preorder(const AVL_Tree_Node* root);
int getHeight(const AVL_Tree_Node* root);

int main() {
	int n, data;
	while (cin >> n) {
		cout << "please input " << n << " data to insert into the avl tree: ";
		AVL_Tree_Node* root = 0;

		for (int i = 0; i < n; ++i)
		{
			cin >> data;
			insert(root, data);
		}
		preorder(root);
		cout << endl;
		cout << root->data << endl;
	}



	cout << endl;
	// system("pause");
}

void insert(AVL_Tree_Node* &root, int data) {
	if (root == 0) {//create new node
		root = new AVL_Tree_Node(data, 0, 0);
	}
	else {
		if (data < root->data) {//insert left
			insert(root->left, data);
			if (getHeight(root->left) - getHeight(root->right) == 2) {//if after insert, not balanced
				if (data < root->left->data) {
					LLRotate(root);
				}
				else if (data > root->left->data) {
					LRRotate(root);
				}
			}
		}
		else if (data > root->data) {
			insert(root->right, data);
			if (getHeight(root->left) - getHeight(root->right) == -2) {
				if (data > root->right->data) {
					RRRotate(root);
				}
				else if (data < root->right->data) {
					RLRotate(root);
				}
			}
		}
	}
}
void preorder(const AVL_Tree_Node* root) {
	if (root) {
		cout << root->data << ends;
		preorder(root->left);
		preorder(root->right);
	}
}
int getHeight(const AVL_Tree_Node* root) {
	if (root == 0)
		return 0;
	else {
		return max(getHeight(root->left), getHeight(root->right)) + 1;
	}
}

void LLRotate(AVL_Tree_Node* &root) {
	AVL_Tree_Node* temp = root->left;
	root->left = temp->right;
	temp->right = root;

	root = temp;
}
void LRRotate(AVL_Tree_Node* &root) {
	RRRotate(root->left);
	LLRotate(root);
}
void RRRotate(AVL_Tree_Node* &root) {
	AVL_Tree_Node* temp = root->right;
	root->right = temp->left;
	temp -> left = root;

	root = temp;
}
void RLRotate(AVL_Tree_Node* &root) {
	LLRotate(root->right);
	RRRotate(root);
}

////c style
// #include <iostream>

// using namespace std;

// struct AVL_Tree_Node
// {
// 	int data;
// 	AVL_Tree_Node* left;
// 	AVL_Tree_Node* right;
// };

// AVL_Tree_Node* insert(AVL_Tree_Node* &root, int data);
// AVL_Tree_Node* LLRotate(AVL_Tree_Node* &root);
// AVL_Tree_Node* LRRotate(AVL_Tree_Node* &root);
// AVL_Tree_Node* RRRotate(AVL_Tree_Node* &root);
// AVL_Tree_Node* RLRotate(AVL_Tree_Node* &root);
// void preorder(AVL_Tree_Node* root);
// int getHeight(AVL_Tree_Node* root);

// int main() {
// 	int n, data;
// 	while (cin >> n) {

// 		AVL_Tree_Node* root = 0;

// 		for (int i = 0; i < n; ++i)
// 		{
// 			cin >> data;
// 			root = insert(root, data);
// 		}
// 		preorder(root);
// 		cout << endl;
// 		cout << root->data;
// 	}



// 	cout << endl;
// 	// system("pause");
// }

// AVL_Tree_Node* insert(AVL_Tree_Node* &root, int data) {
// 	if (root == 0) {
// 		AVL_Tree_Node* node = new AVL_Tree_Node;
// 		node->data = data;
// 		node->left = 0;
// 		node->right = 0;
// 		root = node;
// 	}
// 	else {
// 		if (data < root->data) {
// 			root->left = insert(root->left, data);
// 			if (getHeight(root->left) - getHeight(root->right) == 2) {
// 				if (data < root->left->data) {
// 					root = LLRotate(root);
// 				}
// 				else if (data > root->left->data) {
// 					root = LRRotate(root);
// 				}
// 			}
// 		}
// 		else if (data > root->data) {
// 			root->right = insert(root->right, data);
// 			if (getHeight(root->left) - getHeight(root->right) == -2) {
// 				if (data > root->right->data) {
// 					root = RRRotate(root);
// 				}
// 				else if (data < root->right->data) {
// 					root = RLRotate(root);
// 				}
// 			}
// 		}
// 	}
// 	return root;
// }
// void preorder(AVL_Tree_Node* root) {
// 	if (root) {
// 		cout << root->data << ends;
// 		preorder(root->left);
// 		preorder(root->right);
// 	}
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

// AVL_Tree_Node* LLRotate(AVL_Tree_Node* &root) {
// 	AVL_Tree_Node* temp = root->left;
// 	root->left = temp->right;
// 	temp->right = root;

// 	return temp;
// }
// AVL_Tree_Node* LRRotate(AVL_Tree_Node* &root) {
// 	root->left = RRRotate(root->left);

// 	return LLRotate(root);
// }
// AVL_Tree_Node* RRRotate(AVL_Tree_Node* &root) {
// 	AVL_Tree_Node* temp = root->right;
// 	root->right = temp->left;
// 	temp -> left = root;

// 	return temp;
// }
// AVL_Tree_Node* RLRotate(AVL_Tree_Node* &root) {
// 	root->right = LLRotate(root->right);

// 	return RRRotate(root);
// }











// #include <iostream>

// using namespace std;

// struct BinTreeNode
// {
// 	int data;
// 	BinTreeNode* left;
// 	BinTreeNode* right;
// 	BinTreeNode* parent;
// };

// typedef BinTreeNode* BinTree;

// // class AVL_tree
// // {
// // public:
// // 	BinTree root;
// // public:
// // 	AVL_tree() = default;
// // 	AVL_tree(int node_numbers);
// // 	~AVL_tree() {
// // 		delete_avl(root);
// // 	}
// // 	// void creatBinTree(BinTree& root, int node_numbers);
// // 	void insert(BinTree& node, int data);
// // 	friend int getHeight(BinTree root);
// // 	bool check(BinTree node);
// // 	void balance(BinTree node);
// // 	void leftRotate(BinTree node);
// // 	void leftrightRotate(BinTree node);
// // 	void rightRotate(BinTree node);
// // 	void rightleftRotate(BinTree node);
// // 	void delete_avl(BinTree& node);
// // };

// void creatBinTree(BinTree& root, int node_numbers);
// BinTree insert(BinTree& node, int data);
// int getHeight(BinTree root);
// bool check(BinTree node);
// void balance(BinTree node);
// void leftRotate(BinTree node);
// void leftrightRotate(BinTree node);
// void rightRotate(BinTree node);
// void rightleftRotate(BinTree node);

// int max(int a, int b);
// void delete_avl(BinTree& root);


// int main() {
// 	int n;
// 	cin >> n;
// 	// AVL_tree avl_tree(n);
// 	BinTree root = 0;
// 	creatBinTree(root, n);
// 	if (check(root))
// 		cout << "----------balance" << endl;
// 	else
// 		cout << "----------not balance" << endl;

// 	cout << root->data << endl;

// 	delete_avl(root);
// 	cout << endl;
// 	system("pause");
// 	return 0;
// }

// void creatBinTree(BinTree& root, int node_numbers) {
// 	int data;
// 	for (int i = 0; i < node_numbers; i++) {
// 		cin >> data;
// 		root = insert(root, data);
// 		cout << root->data << endl;
// 	}
// }

// BinTree insert(BinTree& node, int data) {
// 	if (node == 0) {
// 		node = new BinTreeNode;
// 		node->data = data;
// 		node->left = 0;
// 		node->right = 0;
// 		node->parent = 0;
// 	}
// 	else if (data < node->data) {
// 		// cout << node->data << " data < node->data" << endl;
// 		// system("pause");

// 		if (node->left == 0) {
// 			BinTree temp = new BinTreeNode;
// 			temp->data = data;
// 			temp->left = 0;
// 			temp->right = 0;
// 			temp->parent = node;
// 			node->left = temp;
// 			balance(node->left);
// 		}
// 		else
// 			insert(node->left, data);
// 	}
// 	else if (data > node->data) {
// 		// cout << node->data << " data > node->data" << endl;
// 		// system("pause");

// 		if (node->right == 0) {
// 			BinTree temp = new BinTreeNode;
// 			temp->data = data;
// 			temp->right = 0;
// 			temp->right = 0;
// 			temp->parent = node;
// 			node->right = temp;
// 			balance(node->right);
// 		}
// 		else
// 			insert(node->right, data);
// 	}
// 	while (node->parent != 0)
// 		node = node->parent;
// 	return node;
// }

// int getHeight(BinTree root) {
// 	if (root == 0)
// 		return 0;
// 	else
// 		return max(getHeight(root->left), getHeight(root->right)) + 1;
// }

// int max(int a, int b) {
// 	return a > b ? a : b;
// }

// bool check(BinTree node) {
// 	if (getHeight(node->left) - getHeight(node->right) > 1 || getHeight(node->left) - getHeight(node->right) < -1)
// 		return false;
// 	else
// 		return true;
// }
// void balance(BinTree node) {
// 	while (node->parent != 0 && node->parent->parent != 0 && check(node->parent->parent))
// 		node = node->parent;
// 	if (node->parent != 0 && node->parent->parent != 0)
// 	{	//if node is not balanced
// 		if (node->parent->parent->left == node->parent && node->parent->left == node ) {
// 			leftRotate(node->parent);
// 		}
// 		else if (node->parent->parent->right == node->parent && node->parent->right == node )
// 		{
// 			rightRotate(node->parent);
// 		}
// 		else if (node->parent->parent->left == node->parent && node->parent->right == node ) {
// 			leftrightRotate(node->parent);
// 		}
// 		else if (node->parent->parent->right == node->parent && node->parent->left == node ) {
// 			rightleftRotate(node->parent);
// 		}
// 	}
// }


// void leftRotate(BinTree node) {
// 	BinTree temp = node->parent;
// 	if (node->parent->parent->left == node->parent) {
// 		node = node->parent->parent->left;
// 		node->parent = temp->parent;
// 	}
// 	else {
// 		node = node->parent->parent->right;
// 		node->parent = temp->parent;
// 	}

// 	temp->left = node->right;
// 	node->right->parent = temp;

// 	node->right = temp;
// 	temp->parent = node;

// }
// void leftrightRotate(BinTree node) {
// 	BinTree temp = node->right;

// 	node->parent->left = node->right;
// 	node->right->parent = node->parent;

// 	node->right = temp->left;
// 	temp->left->parent = node;

// 	temp->left = node;
// 	node->parent = temp;

// 	leftRotate(node->parent);
// }
// void rightRotate(BinTree node) {
// 	BinTree temp = node->parent;
// 	if (node->parent->parent->left == node->parent) {
// 		node = node->parent->parent->left;
// 		node->parent = temp->parent;
// 	}
// 	else {
// 		node = node->parent->parent->right;
// 		node->parent = temp->parent;
// 	}
// 	temp->right = node->left;
// 	node->left->parent = temp;

// 	node->left = temp;
// 	temp->parent = node;

// }
// void rightleftRotate(BinTree node) {
// 	BinTree temp = node->left;

// 	node->parent->right = node->left;
// 	node->left->parent = node->parent;

// 	node->left = temp->right;
// 	temp->right->parent = node;

// 	temp->right = node;
// 	node->parent = temp;

// 	rightRotate(node->parent);
// }

// void delete_avl(BinTree& node) {
// 	if (node->left)
// 		delete_avl(node->left);
// 	if (node->right)
// 		delete_avl(node->right);
// 	delete node;
// }

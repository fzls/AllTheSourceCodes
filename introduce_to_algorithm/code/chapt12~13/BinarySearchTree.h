#pragma once
#include <iostream>
using namespace std;

class TreeNode
{
public:
	int key;
	TreeNode *left;
	TreeNode *right;
	TreeNode *parent;
public:
	TreeNode(int _key = 0, TreeNode *_left = NULL, TreeNode *_right = NULL, TreeNode *_parent = NULL): key{_key}, left{_left}, right{_right}, parent{_parent} {}
	TreeNode(const TreeNode &node): key{node.key}, left{node.left}, right{node.right}, parent{node.parent} {}
	TreeNode &operator=(const TreeNode &node) {
		key = node.key;
		left = node.left;
		right = node.right;
		parent = node.parent;
		return *this;
	}

	~TreeNode() {}
	void print() {
		cout << key << " ";
	}
};

class BinarySearchTree
{
private:
	TreeNode *NIL;
	TreeNode *root;
public:
	BinarySearchTree(): NIL{new TreeNode}, root{NIL} {
		cout << "enter the number of nodes and the node to insert" << endl;
		int num, key;
		cin >> num;
		while (num-- != 0) {
			cin >> key;
			insert(key);
		}
	}

	~BinarySearchTree() {
		makeEmpty(root);
		delete NIL;
	}

	int maximum();
	int minimum();
	void preorder();
	void inorder();
	void postorder();
	bool search(int key);
	void insert(int key);
	void remove(int key);

private:
	void makeEmpty(TreeNode *T);
	TreeNode *maximum(TreeNode *T);
	TreeNode *minimum(TreeNode *T);
	void preorder(TreeNode *T);
	void inorder(TreeNode *T);
	void postorder(TreeNode *T);
	void visit(TreeNode *T);
	bool search(TreeNode *T, int key);
	void insert(TreeNode *&T, int key);
	void remove(TreeNode *T, int key);
	void transplant(TreeNode *u, TreeNode *v);

	TreeNode *successor(TreeNode *node);
	TreeNode *predecessor(TreeNode *node);
};

int BinarySearchTree::maximum() {
	if (root != NIL)
		return maximum(root)->key;
	else
		return -1;
}

int BinarySearchTree::minimum() {
	if (root != NIL)
		return minimum(root)->key;
	else
		return -1;
}

void BinarySearchTree::preorder() {
	preorder(root);
	cout << endl;
}

void BinarySearchTree::inorder() {
	inorder(root);
	cout << endl;
}

void BinarySearchTree::postorder() {
	postorder(root);
	cout << endl;
}

bool BinarySearchTree::search(int key) {
	return search(root, key);
}

void BinarySearchTree::insert(int key) {
	if (root != NIL)
		insert(root, key);
	else
		root = new TreeNode(key, NIL, NIL, NIL);
}

void BinarySearchTree::remove(int key) {
	remove(root, key);
}

void BinarySearchTree::makeEmpty(TreeNode *T) {
	if (T != NIL) {
		makeEmpty(T->left);
		makeEmpty(T->right);
		delete T;
		T = NIL;
	}
}

TreeNode *BinarySearchTree::maximum(TreeNode *T) {
	while (T != NIL && T->right != NIL)
		T = T->right;
	return T;
}

TreeNode *BinarySearchTree::minimum(TreeNode *T) {
	while (T != NIL && T->left != NIL)
		T = T->left;
	return T;
}

void BinarySearchTree::preorder(TreeNode *T) {
	if (T != NIL) {
		visit(T);
		preorder(T->left);
		preorder(T->right);
	}
}

void BinarySearchTree::inorder(TreeNode *T) {
	if (T != NIL) {
		inorder(T->left);
		visit(T);
		inorder(T->right);
	}
}

void BinarySearchTree::postorder(TreeNode *T) {
	if (T != NIL) {
		postorder(T->left);
		postorder(T->right);
		visit(T);
	}
}

void BinarySearchTree::visit(TreeNode *T) {
	if (T != NIL)
		T->print();
}

bool BinarySearchTree::search(TreeNode *T, int key) {
	if (T != NIL) {
		if (key == T->key)
			return true;
		else if (key < T->key)
			return search(T->left, key);
		else
			return search(T->right, key);
	}
	else
		return false;
}

void BinarySearchTree::insert(TreeNode *&T, int key) {
	if (T != NIL) {
		if (key < T->key) {
			insert(T->left, key);
			T->left->parent = T;
		}
		else if (key > T->key) {
			insert(T->right, key);
			T->right->parent = T;
		}
	}
	else {
		T = new TreeNode(key, NIL, NIL, NIL);
	}
}

void BinarySearchTree::remove(TreeNode *T, int key) {//cause we have parent member variable, so we don't need to use TreeNode * &T to store the info about the relationship bewtween *T and *T's parent(left child or right child)
	if (T != NIL) {
		if (key == T->key) {
			if (T->left == NIL) {
				transplant(T, T->right);
			}
			else if (T->right == NIL) {
				transplant(T, T->left);
			}
			else {
				TreeNode *minimumOfRightSubTree = minimum(T->right);
				if (minimumOfRightSubTree->parent != T) {
					transplant(minimumOfRightSubTree, minimumOfRightSubTree->right);
					minimumOfRightSubTree->right = T->right;
					minimumOfRightSubTree->right->parent = minimumOfRightSubTree;
				}
				transplant(T, minimumOfRightSubTree);
				minimumOfRightSubTree->left = T->left;
				minimumOfRightSubTree->left->parent = minimumOfRightSubTree;
			}
			delete T;
		}
		else if (key < T->key)
			remove(T->left, key);
		else
			remove(T->right, key);
	}
}

void BinarySearchTree::transplant(TreeNode *u, TreeNode *v) {
	if (u->parent == NIL)
		root = v;
	else if (u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;
	if (v != NIL)
		v->parent = u->parent;
}


TreeNode *BinarySearchTree::successor(TreeNode *node) {
	TreeNode *T = node->right;
	while (T->left != NIL)
		T = T->left;
	return T;
}

TreeNode *BinarySearchTree::predecessor(TreeNode *node) {
	TreeNode *T = node->left;
	while (T->right != NIL)
		T = T->right;
	return T;
}

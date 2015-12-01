#pragma once
#include <iostream>
using namespace std;

class TreeNode {
public:
	int key;
	TreeNode *left;
	TreeNode *right;
	TreeNode *parent;
public:
	TreeNode(int _key = NULL, TreeNode *_left = NULL, TreeNode *_right = NULL, TreeNode *_parent = NULL) : key{ _key }, left{ _left }, right{ _right }, parent{ _parent } {}
	TreeNode(const TreeNode &node) : key{ node.key }, left{ node.left }, right{ node.right }, parent{ node.parent } {}
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

class BinarySearchTree {
private:
	TreeNode *root;
public:
	BinarySearchTree() : root{ NULL } {
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
	int maximum(TreeNode *T);
	int minimum(TreeNode *T);
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
	return maximum(root);
}

int BinarySearchTree::minimum() {
	return minimum(root);
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
	insert(root, key);
}

void BinarySearchTree::remove(int key) {
	remove(root, key);
}

void BinarySearchTree::makeEmpty(TreeNode *T) {
	if (T) {
		makeEmpty(T->left);
		makeEmpty(T->right);
		delete T;
		T = NULL;
	}
}

int BinarySearchTree::maximum(TreeNode *T) {
	while (T->right != NULL) //suppose T is not NULL
		T = T->right;
	return T->key;
}

int BinarySearchTree::minimum(TreeNode *T) {
	while (T->left != NULL) //suppose T is not NULL
		T = T->left;
	return T->key;
}

void BinarySearchTree::preorder(TreeNode *T) {
	if (T) {
		visit(T);
		preorder(T->left);
		preorder(T->right);
	}
}

void BinarySearchTree::inorder(TreeNode *T) {
	if (T) {
		inorder(T->left);
		visit(T);
		inorder(T->right);
	}
}

void BinarySearchTree::postorder(TreeNode *T) {
	if (T) {
		postorder(T->left);
		postorder(T->right);
		visit(T);
	}
}

void BinarySearchTree::visit(TreeNode *T) {
	if (T)
		T->print();
}

bool BinarySearchTree::search(TreeNode *T, int key) {
	if (T) {
		if (key == T->key)
			return true;
		else if (key < T->key)
			return search(T->left, key);
		else
			return search(T->right, key);
	} else
		return false;
}

void BinarySearchTree::insert(TreeNode *&T, int key) {
	if (T) {
		if (key < T->key) {
			insert(T->left, key);
			T->left->parent = T;
		} else if (key > T->key) {
			insert(T->right, key);
			T->right->parent = T;
		}
	} else {
		T = new TreeNode(key);
	}
}

void BinarySearchTree::remove(TreeNode *T, int key) {//cause we have parent member variable, so we don't need to use TreeNode * &T to store the info about the relationship bewtween *T and *T's parent(left child or right child)
	if (T) {
		if (key == T->key) {
			if (T->left == NULL) {
				transplant(T, T->right);
			} else if (T->right == NULL) {
				transplant(T, T->left);
			} else {
				TreeNode *minimumOfRightSubTree = successor(T);
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
		} else if (key < T->key)
			remove(T->left, key);
		else
			remove(T->right, key);
	}
}

void BinarySearchTree::transplant(TreeNode *u, TreeNode *v) {
	if (u->parent == NULL)
		root = v;
	else if (u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;
	if (v)
		v->parent = u->parent;
}


TreeNode *BinarySearchTree::successor(TreeNode *node) {
	TreeNode *T = node->right;
	while (T->left)
		T = T->left;
	return T;
}

TreeNode *BinarySearchTree::predecessor(TreeNode *node) {
	TreeNode *T = node->left;
	while (T->right)
		T = T->right;
	return T;
}

#pragma once
#include "BinarySearchTree.h"

enum Color {
	RED,
	BLACK
};


template<typename dataType>
class RedBlackTreeNode {
public:
	dataType key;
	RedBlackTreeNode *left;
	RedBlackTreeNode *right;
	RedBlackTreeNode *parent;
	Color color;

public:
	RedBlackTreeNode(dataType k = dataType(), RedBlackTreeNode *l = NULL, RedBlackTreeNode *r = NULL, RedBlackTreeNode *p = NULL, Color c = BLACK) : key{ k }, left{ l }, right{ r }, parent{ p }, color{ c } {}
	RedBlackTreeNode(const RedBlackTreeNode &node) : key{ node.key }, left{ node.left }, right{ node.right }, parent{ node.parent }, color{ node.color } {}
	RedBlackTreeNode &operator=(const RedBlackTreeNode &node) {
		key = node.key;
		left = node.left;
		right = node.right;
		parent = node.parent;
		color = node.color;
		return *this;
	}
	~RedBlackTreeNode() {}
	void print() {
		cout << key << " ";
	}
};

template<class TreeNode>
class RedBlackTree : public BinarySearchTree<TreeNode> {
private:
	TreeNode *&root;
	TreeNode *&NIL;
public:
	RedBlackTree() : root{ BinarySearchTree<TreeNode>::root }, NIL{ BinarySearchTree<TreeNode>::NIL } {}
	~RedBlackTree() {}
	void insert(decltype(TreeNode::key) key);
	void remove(decltype(TreeNode::key) key);
	void insert(TreeNode *&T, decltype(TreeNode::key) key, TreeNode *parent);
	void insertFixup(TreeNode *T);

	void remove(TreeNode *T, decltype(TreeNode::key) key);
	void removeFixup(TreeNode *T);

	void leftRotate(TreeNode *T);
	void rightRotate(TreeNode *T);

};

template<class TreeNode>
void RedBlackTree<TreeNode>::insert(decltype(TreeNode::key) key) {
	insert(root, key, NIL);
}
template<class TreeNode>
void RedBlackTree<TreeNode>::remove(decltype(TreeNode::key) key) {
	remove(root, key);
}

template<class TreeNode>
void RedBlackTree<TreeNode>::insert(TreeNode *&T, decltype(TreeNode::key) key, TreeNode *parent) {
	if (T != NIL) {
		if (key < T->key) {
			insert(T->left, key, T);
			T->left->parent = T;
		} else if (key > T->key) {
			insert(T->right, key, T);
			T->right->parent = T;
		}
	} else {
		T = new TreeNode(key, NIL, NIL, parent, RED);
		insertFixup(T);
	}
}
template<class TreeNode>
void RedBlackTree<TreeNode>::insertFixup(TreeNode *T) {
	TreeNode *uncle = NIL;
	while (T->parent->color == RED)
		if (T->parent == T->parent->parent->left) {
			uncle = T->parent->parent->right;
			if (uncle->color == RED) {
				T->parent->color = BLACK;
				uncle->color = BLACK;
				T->parent->parent->color = RED;
				T = T->parent->parent;
			} else {
				if (T == T->parent->right) {
					T = T->parent;
					leftRotate(T);
				}
				T->parent->color = BLACK;
				T->parent->parent->color = RED;
				rightRotate(T->parent->parent);
			}
		} else {
			uncle = T->parent->parent->left;
			if (uncle->color == RED) {
				T->parent->color = BLACK;
				uncle->color = BLACK;
				T->parent->parent->color = RED;
				T = T->parent->parent;
			} else {
				if (T == T->parent->left) {
					T = T->parent;
					rightRotate(T);
				}
				T->parent->color = BLACK;
				T->parent->parent->color = RED;
				leftRotate(T->parent->parent);
			}
		}
	root->color = BLACK;
}

template<class TreeNode>
void RedBlackTree<TreeNode>::remove(TreeNode *T, decltype(TreeNode::key) key) {
	if (T != NIL) {
		if (key == T->key) {
			TreeNode *replacedNode = NIL;
			Color removed = T->color;
			if (T->left != NIL && T->right != NIL) {
				TreeNode *minimumOfRightSubTree = this->minimum(T->right);
				replacedNode = minimumOfRightSubTree->right;
				removed = minimumOfRightSubTree->color;
				if (minimumOfRightSubTree->parent != T) {
					this->transplant(minimumOfRightSubTree, minimumOfRightSubTree->right);
					minimumOfRightSubTree->right = T->right;
					minimumOfRightSubTree->right->parent = minimumOfRightSubTree;
				}
				this->transplant(T, minimumOfRightSubTree);
				minimumOfRightSubTree->left = T->left;
				minimumOfRightSubTree->left->parent = minimumOfRightSubTree;
				minimumOfRightSubTree->color = T->color;

			} else if (T->left != NIL) {
				replacedNode = T->left;
				this->transplant(T, T->left);
			} else {
				replacedNode = T->right;
				this->transplant(T, T->right);
			}
			delete T;
			if (removed == BLACK)
				removeFixup(replacedNode);
		} else if (key < T->key)
			remove(T->left, key);
		else
			remove(T->right, key);
	}
}

template<class TreeNode>
void RedBlackTree<TreeNode>::removeFixup(TreeNode *T) {

}

template<class TreeNode>
void RedBlackTree<TreeNode>::leftRotate(TreeNode *T) {
	TreeNode *rightChild = T->right;
	T->right = rightChild->left;
	if (rightChild->left != NIL)
		rightChild->left->parent = T;
	rightChild->parent = T->parent;
	if (T->parent == NIL)
		root = rightChild;
	else if (T == T->parent->left)
		T->parent->left = rightChild;
	else
		T->parent->right = rightChild;
	rightChild->left = T;
	T->parent = rightChild;
}

template<class TreeNode>
void RedBlackTree<TreeNode>::rightRotate(TreeNode *T) {
	TreeNode *leftChild = T->left;
	T->left = leftChild->right;
	if (leftChild->right != NIL)
		leftChild->right->parent = T;
	leftChild->parent = T->parent;
	if (T->parent == NIL)
		root = leftChild;
	else if (T == T->parent->left)
		T->parent->left = leftChild;
	else
		T->parent->right = leftChild;
	leftChild->right = T;
	T->parent = leftChild;
}

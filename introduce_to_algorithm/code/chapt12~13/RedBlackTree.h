#pragma once
#include "BinarySearchTree.h"

enum Color
{
	RED,
	BLACK
};


template<typename dataType>
class RedBlackTreeNode
{
public:
	dataType key;
	Color color;
	RedBlackTreeNode *left;
	RedBlackTreeNode *right;
	RedBlackTreeNode *parent;

public:
	RedBlackTreeNode(dataType k = dataType(), Color c = BLACK, RedBlackTreeNode *l = NULL, RedBlackTreeNode *r = NULL, RedBlackTreeNode *p = NULL): key{k}, color{c}, left{l}, right{r}, parent{p} {}
	RedBlackTreeNode(const RedBlackTreeNode &node): key{node.key}, color{node.color}, left{node.left}, right{node.right}, parent{node.parent} {}
	RedBlackTreeNode &operator=(const RedBlackTreeNode &node) {
		key = node.key;
		color = node.color;
		left = node.left;
		right = node.right;
		parent = node.parent;
		return *this;
	}
	~RedBlackTreeNode() {}
	void print() {
		cout << key << " ";
	}
};

template<class TreeNode>
class RedBlackTree : public BinarySearchTree
{
private:

public:
	RedBlackTree(/* args */):/* initialize */ {}
	~RedBlackTree() {}

};

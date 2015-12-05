/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 testRBT.cpp
* @version:
* @Time: 		 2015-12-05 10:05:11
* @Description:  test RedBlackTree
*
+----------------------------------------------------------
*/
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>
#include <cassert>

#include "RedBlackTree.h"


using namespace std;
template<class T>
void testConstructor(T &node) {
	assert(node.key == 233);
	assert(node.color == BLACK);
	assert(node.left == NULL);
	assert(node.right == NULL);
	assert(node.parent == NULL);
}

template<class T>
void testCopyConstructor(T &node) {
	testConstructor(node);
}

template<class T>
void testAssignment(T &node) {
	testConstructor(node);
}

int main() {
	// freopen("test.in", "r", stdin);
	// freopen("test.out", "w", stdout);
	RedBlackTreeNode<int> node(233);
	testConstructor(node);

	RedBlackTreeNode<int> node2(node), node3;
	testCopyConstructor(node2);

	node3 = node;
	testAssignment(node3);



	cout << endl;
	system("pause");
	return 0;
}

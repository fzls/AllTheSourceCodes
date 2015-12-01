/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 testBST.cpp
* @version:
* @Time: 		 2015-11-30 19:41:40
* @Description:  test the BinarySearchTree Class
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
#include "BinarySearchTree.h"

using namespace std;



int main() {
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	BinarySearchTree<BinarySearchTreeNode> bst;
	cout << "max: " << bst.maximum() << endl;
	cout << "min: " << bst.minimum() << endl;
	bst.preorder();
	bst.inorder();
	bst.postorder();
	for (int i = 1; i < 25; i += 3)
		if (bst.search(i))
			cout << i << " is found" << endl;
		else
			cout << i << " is not found" << endl;
	for (int i = 1; i < 25; i ++) {
		bst.remove(i);
		bst.preorder();
	}

	cout << endl;
	system("pause");
	return 0;
}

/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 Tree_Traversals_Again.cpp
* @version:
* @Time: 		 2015-09-03 15:13:24
* @Description:  03-树3 Tree Traversals Again   (25分)
*
+----------------------------------------------------------
*/
#include <iostream>
// #include <list>
#include <string>


using namespace std;
static int count ;

struct BinTreeNode
{
	BinTreeNode(): data(0), visited(false), left(0), right(0), parent(0)  {}
	int data;
	bool visited ;
	BinTreeNode *left, *right, *parent ;
};

void postorder_travesal(BinTreeNode* root);

int main() {
	// list<BinTreeNode> BinTree;

	BinTreeNode *node, *pre, *root = 0;
	bool push_after_pop = false;
	bool pop_after_push = false;
	int n;
	cin >> n;
	string order;
	int x ;
	n *= 2; //2n orders
	for (int i = 0; i < n; i++) {
		cin >> order;
		if (order == "Push") {
			cin >> x;
			if (push_after_pop) {
				// temp =pre;
				pre = node;
				node = new BinTreeNode;
				node->data = x;
				node->left = 0;
				node->right = 0;

				node->parent = pre;
				pre->right = node;
				pre = node;
				push_after_pop = false;


			}
			else {
				node = new BinTreeNode;
				node->data = x;
				node->left = 0;
				node->right = 0;
				if (root == 0) {
					node->parent = 0;
					root = node;
				}
				else {
					node->parent = pre;
					pre->left = node;
				}
				pre = node;
			}
			pop_after_push = true;
		}
		else if (order == "Pop") {
			if (pop_after_push) {
				// pre = node->parent;
				node->visited = true;
				pop_after_push = false;
			}
			else {
				if (node->parent->visited == false) {
					// node = pre;
					// pre = pre->parent;
					node = node->parent;
					node->visited = true;
				}
				else {
					while (node->parent->parent->left != node->parent) {
						node = node->parent;
					}
					node = node->parent->parent;
					// pre = node;
				}

			}
			push_after_pop = true;
		}
	}
	n = n / 2;
	count = n;
	// cout << count;
	if (n != 0) {
		postorder_travesal(root);
	}
	else
		cout << " ";



	cout << endl;
	system("pause");
	return 0;
}

void postorder_travesal(BinTreeNode* root) {
	if (root) {
		postorder_travesal(root->left);
		postorder_travesal(root->right);
		// cout << "count: " << count << endl;
		cout << root->data << (count-- == 1 ? "" : " ");
	}
}
//ice_camel's version
// #include <stdio.h>
// #include <stdlib.h>

// struct Node {
// 	int tag;		//标记节点是第几次进栈
// 	int num;
// };
// //先序遍历对应进栈顺序，中序遍历对应出栈顺序；
// //后序遍历与中序遍历不同的是节点出栈后要马上再入栈（tag做第二次入栈标记），等右儿子遍历完后再出栈;
// //具体实现上，每次中序遍历的pop时，如果栈顶是标记过的节点（tag=2），循环弹出；如果没有标记过（tag=1），做标记，即弹出再压栈）
// //栈顶tag=2的节点对应中序遍历中已弹出的节点；循环弹出后碰到的第一个tag=1的节点才对应中序遍历当前pop的节点
// int main() {
// 	int n;
// 	scanf("%d", &n);
// 	int flag = 0;
// 	struct Node stack[30];
// 	int size = 0;			//栈元素大小，指向栈顶的下一个位置
// 	for (int i = 0; i < 2 * n; ++i) {
// 		char s[10];
// 		scanf("%s", s);
// 		if (s[1] == 'u') {		//push
// 			scanf("%d", &stack[size].num);		//入栈
// 			stack[size].tag = 1;				//标记第一次入栈
// 			++size;
// 		}
// 		else {					//pop
// 			while (size > 0 && stack[size - 1].tag == 2) {	//循环弹出栈顶tag=2的节点
// 				if (flag)
// 					printf(" ");
// 				flag = 1;
// 				printf("%d", stack[--size].num);
// 			}
// 			if (size > 0)		//将中序遍历中应该要弹出的节点弹出再压栈，做标记即可
// 				stack[size - 1].tag = 2;
// 		}
// 	}
// 	while (size) {				//将栈中剩余节点依次弹出
// 		if (flag) {
// 			printf(" ");
// 		}
// 		flag = 1;
// 		printf("%d", stack[--size].num);
// 	}
// 	system("pause");

// 	return 0;
// }

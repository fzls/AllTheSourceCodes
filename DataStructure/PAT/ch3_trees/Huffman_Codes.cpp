/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 Huffman_Codes.cpp
* @version:
* @Time: 		 2015-09-05 21:10:30
* @Description:  05-树9 Huffman Codes   (30分)
*
+----------------------------------------------------------
*/
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

struct entry//学生的答案中的一个条目
{
	char clear_text;
	string code;
};

// typedef struct TreeNode* HuffmanTree;
using HuffmanTree = struct TreeNode*;
struct TreeNode
{
	string character;
	int weight;
	HuffmanTree left, right;
};

HuffmanTree BuildHuffmanTree(vector<HuffmanTree>& H);//建立霍夫曼树
void BuildMinHeap(vector<HuffmanTree>& H);//建立最小堆
void moveDown(vector<HuffmanTree>& H, int first, int last);//建立最小堆的中间操作
HuffmanTree DeleteMin(vector<HuffmanTree>& H);//删除最小堆的根节点
void Insert(vector<HuffmanTree>& H, HuffmanTree &node);//向最小堆中插入元素
int compute_WPL(HuffmanTree root, int depth);//计算霍夫曼树的权值路径长度
bool check(vector<entry>& record, int WPL, std::map<char, int>& char_freq);//检查该学生的答案是否正确：1、WPL 2、非前缀
bool check_prefix(vector<entry>& record);//检查record中两两是否前缀
// bool compare_code_length(entry& a, entry& b);
bool prefix(string& shorter, string& longer);//检查给定的两个字符串是否构成前缀，是上一个函数的一部分
void sort_entry(vector<entry>& record);//对record按编码长度进行由小到大排序，方便前缀检查
// void preorder(HuffmanTree& root) {
// 	if (root) {
// 		cout << root->character << " " << root->weight << endl;
// 		preorder(root->left);
// 		preorder(root->right);
// 	}

// }

int main() {
	// freopen("test.txt", "r", stdin);//for test
	int n;
	cin >> n;
	std::vector<HuffmanTree> minheap ;//用于保存初始数据的最小堆
	std::map<char, int> char_freq ;//在计算WPL时使用

	//读取第二行输入
	for (int i = 0; i < n; i++) {
		HuffmanTree temp = new TreeNode;
		cin >> temp->character >> temp->weight;
		temp->left = 0;
		temp->right = 0;
		minheap.push_back(temp);
		char_freq.insert(pair<char, int>(temp->character[0], temp->weight));
	}

	//建立霍夫曼树从而计算WPL
	HuffmanTree root = BuildHuffmanTree(minheap);
	// preorder(root);
	// cout << "root->char weight: " << root->character << " " << root->weight << endl;
	// system("pause");
	int WPL = compute_WPL(root, 0);
	// cout << "WPL: " << WPL << endl;
	// system("pause");


	int m;//学生数目
	cin >> m;
	while (m--) {
		std::vector<entry> record ;
		record.clear();
		bool out_of_range = false;
		for (int i = 0; i < n; i++) {
			entry temp;
			cin >> temp.clear_text >> temp.code;
			record.push_back(temp);
			if (char_freq.find(temp.clear_text) == char_freq.end())
				out_of_range = true;
		}
		if (!out_of_range && check(record, WPL, char_freq))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}

	// cout << endl;

	// system("pause");
	return 0;
}

HuffmanTree BuildHuffmanTree(vector<HuffmanTree>& H) {
	int i;
	HuffmanTree node;
	// for (auto k : H)
	// 	cout << k->character << " " << k->weight << endl;
	// system("pause");

	BuildMinHeap(H);
	// for (auto k : H)
	// 	cout << k->character << " " << k->weight << endl;
	// system("pause");
	int size = H.size();//with the insert and delete, the size of the H will change, so we should save it first.
	for (i = 1; i < size; i++) {
		node = new TreeNode;
		node->left = DeleteMin(H);
		node->right = DeleteMin(H);
		node->weight = node->left->weight + node->right->weight;
		node->character = node->left->character + " + " + node->right->character;

		Insert(H, node);
	}
	node = DeleteMin(H);
	return node;
}
void BuildMinHeap(vector<HuffmanTree>& H) {
	int size = H.size();
	for (int i = size / 2 - 1 ; i >= 0; --i)
		moveDown(H, i, size - 1);
}
void moveDown(vector<HuffmanTree>& H, int first, int last) {
	int littleChild = 2 * first + 1;
	while (littleChild <= last) {
		if (littleChild < last && H[littleChild + 1]->weight < H[littleChild]->weight)
			littleChild++;

		if (H[littleChild]->weight < H[first]->weight) {
			swap(H[littleChild], H[first]);
			first = littleChild;
			littleChild = 2 * first + 1;
		}
		else
			littleChild = last + 1;
	}
}


HuffmanTree DeleteMin(vector<HuffmanTree>& H) {
	// cout << "delete: " << H[0]->character << endl;
	int size = H.size();
	HuffmanTree min = H[0];
	H[0] = H[size - 1];
	moveDown(H, 0, size - 2);
	H.erase(H.end() - 1);
	return min;
}
void Insert(vector<HuffmanTree>& H, HuffmanTree &node) {
	// cout << "before insert: H: " << endl;
	// for (auto k : H)
	// 	cout << k->character << " " << k->weight << endl;

	H.push_back(node);
	// cout << "after insert: H: " << endl;
	// for (auto k : H)
	// 	cout << k->character << " " << k->weight << endl;

	int size = H.size() - 1;
	while (size != 0 && H[size]->weight < H[(size - 1) / 2]->weight && size != 0) {
		swap(H[size], H[size / 2]);
		size /= 2;
	}
	// cout << "after insert and adjust: H: " << endl;
	// for (auto k : H)
	// 	cout << k->character << " " << k->weight << endl;
	// system("pause");
}
int compute_WPL(HuffmanTree root, int depth) {
	if (root) {
		if (root->left == 0 && root->right == 0)
			return depth * root->weight;
		else
			return compute_WPL(root->left, depth + 1) + compute_WPL(root->right, depth + 1);
	}
	else return 0;
}
bool check(vector<entry>& record, int WPL, std::map<char, int>& char_freq) {
// 	cout << endl << "-------------check start-------------" << endl;

	int wpl_test = 0;
	int size = record.size();
	for (int i = 0; i < size; i++)
		wpl_test += char_freq[record[i].clear_text] * record[i].code.size();
	if (wpl_test != WPL) {
		// cout << "WPL test fail! " << endl;
		// cout << endl << "-------------check end-------------" << endl;
		return false;

	}
	else {
		// cout << "WPL test passed! " << endl;
		return !check_prefix(record);
	}
}
bool check_prefix(vector<entry>& record) {
	// sort(record.begin(), record.end(), compare_code_length);///////
	sort_entry(record);
	int size = record.size();
	for (int i = 0; i < size - 1; i++)
		for (int j = i + 1; j < size; j++)
			// if (record[i].code == record[j].code.substr(0, record[i].code.size()))
			// 	return true;
			if (prefix(record[i].code, record[j].code)) {
				// cout << "prefix test failed! " << endl;
				// cout << endl << "-------------check end-------------" << endl;
				return true;

			}
	// cout << "prefix test passed! " << endl;
	// cout << endl << "-------------check end-------------" << endl;

	return false;
}

// bool compare_code_length(const entry& a, const entry& b) {
// 	return a.code.size() < b.code.size();
// }
bool prefix(string& shorter, string& longer) {
	int index;
	for (index = 0; index < shorter.size(); index++)
		if (shorter[index] != longer[index])
			break;
	if (index == shorter.size())
		return true;
	else
		return false;
}
void sort_entry(vector<entry>& record) {
	for (int i = 0; i < record.size(); i++)
		for (int j = i; j < record.size() - i - 1; j++)
			if (record[j].code.size() > record[j + 1].code.size())
				swap(record[j], record[j + 1]);
}

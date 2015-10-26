/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 Six_Degrees_of_Separation.cpp
* @version:
* @Time: 		 2015-09-09 16:07:52
* @Description:  06-图3 六度空间   (30分)
*
+----------------------------------------------------------
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>

using namespace std;

class ListUDG
{
private:
	class eNode {
	public:
		eNode(int adj = 0, eNode* n = 0): adjVer(adj), next(n) {}
		int adjVer;
		eNode* next;
	};
	int ver_num;
	int edg_num;
	vector<eNode*> vnodes;
	vector<bool> visited;
public:
	ListUDG(int v, int e): ver_num(v), edg_num(e), vnodes(v + 1), visited(v + 1, false) {
		for (int i = 1; i <= ver_num; i++)
			vnodes[i] = new eNode(i, 0);

		int v1, v2;
		eNode *temp = 0, *p;
		for (int i = 0; i < e; i++) {
			cin >> v1 >> v2;
			temp = new eNode(v2, 0);
			p = vnodes[v1]; //the head pointer
			while (p->next != 0 && p->next->adjVer < v2)
				p = p->next;
			temp->next = p->next;
			p->next = temp;

			temp = new eNode(v1, 0);
			p = vnodes[v2];
			while (p->next != 0 && p->next->adjVer < v1)
				p = p->next;
			temp->next = p->next;
			p->next = temp;
		}
		// for (int i = 0; i < ver_num; i++) {
		// 	cout << i << " : ";
		// 	for (auto j = vnodes[i]->next; j != 0; j = j->next)
		// 		cout << j->adjVer << " ";
		// 	cout << endl;
		// }
	}
	~ListUDG() {
		for (int i = 1; i <= ver_num; i++)
			clear(vnodes[i]);
	}
	void clear(eNode* p) {
		if (p) {
			clear(p->next);
			delete p;
		}
	}

	void BFS(int v, int &count);
	void test_six_degree_separation();
	void reset();

};

void ListUDG::BFS(int v, int &count) {
	if (!visited[v]) {
		int tail, last = v, level = 0;
		visited[v] = true;
		count++;
		queue<int> list_queue;
		list_queue.push(v);
		while (!list_queue.empty()) {
			v = list_queue.front();
			list_queue.pop();
			for (auto i = vnodes[v]->next; i != 0; i = i->next)
				if (!visited[i->adjVer]) {
					visited[i->adjVer] = true;
					count++;
					list_queue.push(i->adjVer);
					tail = i->adjVer;
				}
			if (v == last) {
				level++; last = tail;
			}
			if (level == 6)
				break;
		}
	}
}
void ListUDG::test_six_degree_separation() {
	for (int i = 1; i <= ver_num; i++) {
		int count = 0;
		BFS(i, count);
		cout << i << ": " << fixed << setprecision(2) << 100.0 * count / ver_num << "%" << endl;
		reset();
	}
}
void ListUDG::reset() {
	for (int i = 0; i <= ver_num; i++)
		visited[i] = false;
}


int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int v, e;
	cin >> v >> e;
	ListUDG graph(v, e);
	graph.test_six_degree_separation();

	// cout << endl;
	// system("pause");
	// fclose(stdin);
	// fclose(stdout);
	return 0;
}


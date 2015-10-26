/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 connected_set.cpp
* @version:
* @Time: 		 2015-09-09 12:22:33
* @Description:  06-图1 列出连通集   (25分)
*
+----------------------------------------------------------
*/
#include <iostream>
#include <vector>
#include <limits>
#include <queue>

using namespace std;

class MatrixUDG
{
private:
	int ver_num;
	int edg_num;
	vector<vector<int>> matrix;
	vector<bool> visited;
public:
	MatrixUDG(int v, int e): ver_num(v), edg_num(e), matrix(v, vector<int>(v, 0)), visited(v, false) {
		int v1, v2;
		for (int i = 0; i < e; i++) {
			cin >> v1 >> v2;
			matrix[v1][v2] = 1;
			matrix[v2][v1] = 1;
		}
	}
	~MatrixUDG() {}
	void DFS(int v);
	void DFS_connected();
	void BFS(int v);
	void BFS_connected();
	void reset();

};
void MatrixUDG::reset() {
	for (int i = 0; i < ver_num; i++)
		visited[i] = false;
}

void MatrixUDG::DFS(int v) {
	if (!visited[v]) {
		cout << v << " ";
		visited[v] = true;
		for (int i = 0; i < ver_num; i++)
			if (matrix[v][i] != 0 && !visited[i])
				DFS(i);
	}
}

void MatrixUDG::DFS_connected() {
	for (int i = 0; i < ver_num; i++) {
		if (!visited[i]) {
			cout << "{ ";
			DFS(i);
			cout << "}" << endl;
		}
	}
	reset();

}

void MatrixUDG::BFS(int v) {
	if (!visited[v]) {
		cout << v << " ";
		visited[v] = true;
		queue<int> bfs_queue;
		bfs_queue.push(v);
		while (!bfs_queue.empty()) {
			v = bfs_queue.front();
			bfs_queue.pop();
			for (int i = 0; i < ver_num; i++)
				if (matrix[v][i] != 0 && !visited[i]) {
					cout << i << " ";
					visited[i] = true;
					bfs_queue.push(i);
				}
		}
	}
}

void MatrixUDG::BFS_connected() {
	for (int i = 0; i < ver_num; i++) {
		if (!visited[i]) {
			cout << "{ ";
			BFS(i);
			cout << "}" << endl;
		}
	}
	reset();

}

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
	ListUDG(int v, int e): ver_num(v), edg_num(e), vnodes(v), visited(v, false) {
		for (int i = 0; i < ver_num; i++)
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
		for (int i = 0; i < ver_num; i++)
			clear(vnodes[i]);
	}
	void clear(eNode* p) {
		if (p) {
			clear(p->next);
			delete p;
		}
	}
	void DFS(int v);
	void DFS_connected();
	void BFS(int v);
	void BFS_connected();
	void reset();

};

void ListUDG::DFS(int v) {
	if (!visited[v]) {
		cout << v << " ";
		visited[v] = true;
		for (eNode* i = vnodes[v]->next; i != 0; i = i->next) {
			if (!visited[i->adjVer])
				DFS(i->adjVer);
		}
	}
}
void ListUDG::DFS_connected() {
	for (int i = 0; i < ver_num; i++)
		if (!visited[i]) {
			cout << "{ ";
			DFS(i);
			cout << "}" << endl;
		}
	reset();
}
void ListUDG::BFS(int v) {
	if (!visited[v]) {
		cout << v << " ";
		visited[v] = true;
		queue<int> list_queue;
		list_queue.push(v);
		while (!list_queue.empty()) {
			v = list_queue.front();
			list_queue.pop();

			for (auto i = vnodes[v]->next; i != 0; i = i->next)
				if (!visited[i->adjVer]) {
					cout << i->adjVer << " ";
					visited[i->adjVer] = true;
					list_queue.push(i->adjVer);
				}

		}
	}
}
void ListUDG::BFS_connected() {
	for (int i = 0; i < ver_num; i++) {
		if (!visited[i]) {
			cout << "{ ";
			BFS(i);
			cout << "}" << endl;
		}
	}
	reset();
}
void ListUDG::reset() {
	for (int i = 0; i < ver_num; i++)
		visited[i] = false;
}

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int v, e;
	cin >> v >> e;
	cout << "-------MatrixUDG-------" << endl;
	MatrixUDG graph2(v, e);
	graph2.DFS_connected();
	graph2.BFS_connected();
	cout << "-------ListUDG-------" << endl;
	ListUDG graph(v, e);
	graph.DFS_connected();
	graph.BFS_connected();


	cout << endl;
	system("pause");
	return 0;
}


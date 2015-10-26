/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 cuncuntong.cpp
* @version:
* @Time: 		 2015-09-10 10:53:52
* @Description:  08-图7 公路村村通   (30分)
*
+----------------------------------------------------------
*/
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

struct edge
{
	edge(int a, int b, int c): v1(a), v2(b), weight(c) {}
	int v1;
	int v2;
	int weight;
	bool operator<(edge& e) {
		return weight < e.weight;
	}
	bool operator>(edge& e) {
		return weight > e.weight;
	}
};

class Heap
{
private:
	vector<edge> elements;
public:
	Heap() {}
	~Heap() {}
	void print() {
		for (auto k : elements)
			cout << k.v1 << " " << k.v2 << " " << k.weight << endl;
	}
	bool empty() {
		return elements.empty();
	}
	void insert(edge& e) {
		elements.push_back(e);
		int n = elements.size() - 1;
		while (n != 0 && elements[n] < elements[(n - 1) / 2]) {
			swap(elements[n], elements[(n - 1) / 2]);
			n = (n - 1) / 2;
		}
	}
	void moveDown(int first, int last) {
		int less = 2 * first + 1;
		while (less <= last) {
			if (less < last && elements[less] > elements[less + 1])
				less++;
			if (elements[less] < elements[first]) {
				swap(elements[less], elements[first]);
				first = less;
				less = 2 * first + 1;
			}
			else
				less = last + 1;
		}
	}

	edge delete_heap() {
		edge temp = elements[0];
		elements[0] = elements[elements.size() - 1];
		elements.pop_back();
		moveDown(0, elements.size() - 1);
		return temp;
	}

};

class MatrixUDG
{
private:
	int ver_num;
	int edg_num;
	int min_cost;
	int count;
	vector<vector<int>> matrix;
	vector<bool> visited;
	vector<int> US_set;
	Heap heap;
public:
	MatrixUDG(int v, int e): ver_num(v), edg_num(e), min_cost(0), count(0) , matrix(v + 1, vector<int>(v + 1, INT_MAX)), visited(v + 1, false), US_set(v + 1, -1) {
		int v1, v2, cost;
		for (int i = 0; i < e; i++) {
			cin >> v1 >> v2 >> cost;
			matrix[v1][v2] = cost;
			matrix[v2][v1] = cost;
			edge temp(v1, v2, cost);
			heap.insert(temp);
		}
		// heap.print();
	}
	~MatrixUDG() {}
	int root(int v) {
		if (US_set[v] < 0)
			return v;
		else
			return US_set[v] = root(US_set[v]);
	}

	void Union(int v1, int v2) {
		int root1 = root(v1);
		int root2 = root(v2);
		if (US_set[root1] <= US_set[root2]) {
			US_set[root1] += US_set[root2];
			US_set[root2] = root1;
		}
		else {
			US_set[root2] += US_set[root1];
			US_set[root1] = root2;
		}
	}
	void min_spining_tree();
};
void MatrixUDG::min_spining_tree() {
	while (count < ver_num - 1 && !heap.empty()) {
		edge temp = heap.delete_heap();
		while (visited[temp.v1] && visited[temp.v2] && !heap.empty()) {
			temp = heap.delete_heap();
		}
		if (!(visited[temp.v1] && visited[temp.v2])) {
			// cout << temp.v1 << " " << temp.v2 << " " << temp.weight << endl;
			min_cost += temp.weight;
			visited[temp.v1] = visited[temp.v2] = true;
			count++;
		}
	}
	// cout << "count : " << count << endl;
	if (count == ver_num - 1)
		cout << min_cost << endl;
	else
		cout << "-1" << endl;

}


int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int v, e;
	cin >> v >> e;
	MatrixUDG graph(v, e);
	graph.min_spining_tree();

	// cout << endl;
	// system("pause");
	return 0;
}

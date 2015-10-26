/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 travel_schedule.cpp
* @version:
* @Time: 		 2015-09-10 09:45:35
* @Description:  07-图6 旅游规划   (25分)
*
+----------------------------------------------------------
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
const int MAX = INT_MAX / 2 - 100;
using namespace std;

struct Road
{
	Road(int l = MAX, int c = MAX): length(l), cost(c) {}
	int length;
	int cost;
};

class MatrixUDG
{
private:
	int ver_num;
	int edg_num;
	vector<vector<Road>> matrix;
	vector<Road> distance;
	vector<bool> collected;
public:

	MatrixUDG(int v, int e): ver_num(v), edg_num(e), matrix(v, vector<Road>(v)), distance(v), collected(v, false) {
		int v1, v2, l, c;
		for (int i = 0; i < e; i++) {
			cin >> v1 >> v2 >> l >> c;
			matrix[v1][v2] = Road(l, c);
			matrix[v2][v1] = Road(l, c);
		}
	}
	~MatrixUDG() {}
	void schedule(int start, int end);
	int find_min_length();//how to use heap to implment it, which should also allow change of distance;
};

int MatrixUDG::find_min_length() {
	int index = -1;
	for (int i = 0; i < ver_num; i++)
		if (!collected[i]) {
			index = i;
			for (int j = 0; j < ver_num; j++)
				if (!collected[j] && distance[index].length > distance[j].length)
					index = j;
			break;
		}
	return index;
}


void MatrixUDG::schedule(int start, int end) {
	for (int i = 0; i < ver_num; i++)
		distance[i] = matrix[start][i];

	distance[start].length = 0;
	distance[start].cost = 0;

	while (1) {
		int v = find_min_length();
		if (v == -1)
			break;
		collected[v] = true;
		for (int i = 0; i < ver_num; i++)
			if (!collected[i] && matrix[v][i].length != MAX && (distance[i].length > distance[v].length + matrix[v][i].length || (distance[i].length == distance[v].length + matrix[v][i].length && distance[i].cost > distance[v].cost + matrix[v][i].cost))) {
				distance[i].length = distance[v].length + matrix[v][i].length;
				distance[i].cost = distance[v].cost + matrix[v][i].cost;
			}
	}
	cout << distance[end].length << " " << distance[end].cost << endl;
}


int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int v, e, start, end;
	cin >> v >> e >> start >> end;
	MatrixUDG graph(v, e);
	graph.schedule(start, end);


	// cout << endl;
	// system("pause");
	return 0;
}


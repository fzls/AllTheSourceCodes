/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 hari's_test.cpp
* @version:
* @Time: 		 2015-09-09 19:44:01
* @Description:  07-图4 哈利·波特的考试   (25分)
*floyd algorithm with matrix UDG
+----------------------------------------------------------
*/
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class MatrixUDG
{
private:
	int ver_num;
	int edg_num;
	vector<vector<int>> matrix;
	vector<vector<int>> min_distance;
	vector<int> max_min_distance;//if use index with 1~N, remember to allocate n+1 space in memory
	vector<bool> visited;
public:
	MatrixUDG(int v, int e): ver_num(v), edg_num(e), matrix(v + 1, vector<int>(v + 1, INT_MAX / 2 - 100)), min_distance(v + 1, vector<int>(v + 1, INT_MAX / 2 - 100)) , max_min_distance(v + 1, 0), visited(v + 1, false) {
		int v1, v2, weight;
		for (int i = 0; i < e; i++) {
			cin >> v1 >> v2 >> weight;
			matrix[v1][v2] = weight;
			matrix[v2][v1] = weight;
		}
	}
	~MatrixUDG() {}
	bool BFS_test_connected(int v);
	bool BFS_test_connected();
	void search_min_max_min();
	void floyd();

};

void MatrixUDG::floyd() {
	for (int i = 1; i <= ver_num; i++)
		for (int j = 1; j <= ver_num; j++)
			min_distance[i][j] = matrix[i][j];

	for (int k = 1; k <= ver_num; k++)
		for (int i = 1; i <= ver_num; i++)
			for (int j = 1; j <= ver_num; j++)
				if (i != j && min_distance[i][j] > min_distance[i][k] + min_distance[k][j])
					min_distance[i][j] = min_distance[i][k] + min_distance[k][j];
}

void MatrixUDG::search_min_max_min() {
	floyd();
	for (int i = 1; i <= ver_num; i++)
		for (int j = 1; j <= ver_num; j++)
			if (i != j && max_min_distance[i] < min_distance[i][j])
				max_min_distance[i] = min_distance[i][j];
	int min_index = 1;
	for (int i = 1; i <= ver_num; i++)
		if (max_min_distance[min_index] > max_min_distance[i])
			min_index = i;
	cout << min_index << " " << max_min_distance[min_index] << endl;
}

bool MatrixUDG::BFS_test_connected() {
	return BFS_test_connected(1);
}

bool MatrixUDG::BFS_test_connected(int v) {
	int count = 0;
	if (!visited[v]) {
		count++;
		visited[v] = true;
		queue<int> bfs_queue;
		bfs_queue.push(v);
		while (!bfs_queue.empty()) {
			v = bfs_queue.front(); bfs_queue.pop();
			for (int i = 1; i <= ver_num; i++)
				if (!visited[i] && matrix[v][i] != INT_MAX / 2 - 100) {
					count++;
					visited[i] = true;
					bfs_queue.push(i);
				}
		}
	}
	return count == ver_num;
}

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int v, e;
	cin >> v >> e;
	MatrixUDG graph(v, e);
	if (graph.BFS_test_connected())
		graph.search_min_max_min();
	else
		cout << "0" << endl;


	// cout << endl;
	// system("pause");
	// fclose(stdin);
	// fclose(stdout);
	return 0;
}


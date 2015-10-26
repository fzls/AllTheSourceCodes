/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 basic_implemention.cpp
* @version:
* @Time: 		 2015-09-08 20:54:42
* @Description:
*
+----------------------------------------------------------
*/
#include <iostream>
#include <vector>
#include <map>
#include <limits>
#include <list>

using namespace std;

class AdjacentMatrixUDG
{
public:
	int vertex_num;
	map<char, int > vertexs;
	vector<vector<int>> edges;
public:
	AdjacentMatrixUDG(int ver = 1): vertex_num(ver), edges(vertex_num, vector<int>(vertex_num, INT_MAX)) {
		cout << "please input " << vertex_num << " vertexs" << endl;
		char vertex;
		for (int i = 0; i < vertex_num; i++) {
			cin >> vertex;
			vertexs.insert(pair<char, int>(vertex, i));
		}
		cout << "please input the edges in the form : vertex1 vertex2 weight and end by input #" << endl;
		char vertex1, vertex2;
		int  weight;
		cin >> vertex1;
		while (vertex1 != '#') {
			cin >> vertex2 >> weight;
			edges[vertexs[vertex1]][vertexs[vertex2]] = weight;
			edges[vertexs[vertex2]][vertexs[vertex1]] = weight;
			cin >> vertex1;
		}

	}
	~AdjacentMatrixUDG() {}

};

// struct AdjListNode
// {
// 	AdjListNode(char adj, int wg):adjvertex(adj),weight(wg){}
// 	char adjvertex = '0';
// 	int weight = 0;
// };

// struct Vertex_Node
// {
// 	char vertex = '0';
// 	list<AdjListNode> adjacents;
// };
// class AdjacencyListGraph
// {
// private:
// 	int vertex_num;
// 	vector<Vertex_Node>  vertexs;
// 	map<char, int> vertex_char_to_index;
// public:
// 	AdjacencyListGraph(int ver): vertex_num(ver) {
// 		cout << "please input vertexs" << endl;
// 		for (int i = 0; i < vertex_num; i++) {
// 			Vertex_Node temp;
// 			cin >> temp.vertex;
// 			vertexs.push_back(temp);
// 			vertex_char_to_index.insert(pair<char,int>(temp.vertex,i));
// 		}
// 		cout<<"please input edges, end with #"<<endl;
// 		char vertex1,vertex2,weight;
// 		cin>>vertex1;
// 		while(vertex1!='#'){
// 			cin>>vertex2>>weightl;
// 			vertexs[vertex_char_to_index[vertex1]].adjacents.push_front(AdjListNode())

// 			cin>>vertex1;
// 		}
// 	}
// 	~AdjacencyListGraph() {}

// };

int main() {
	// freopen("test.txt", "r", stdin);
	int ver_num;
	cin >> ver_num;
	// AdjacentMatrixUDG graph(ver_num);




	cout << endl;
	system("pause");
	return 0;
}


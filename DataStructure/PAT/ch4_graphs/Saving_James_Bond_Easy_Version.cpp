/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 Saving_James_Bond_Easy_Version.cpp
* @version:
* @Time: 		 2015-09-09 15:16:17
* @Description:  06-图2 Saving James Bond - Easy Version   (25分)
*
+----------------------------------------------------------
*/
#include <iostream>
#include <vector>

using namespace std;

struct Point
{
	Point(int a = 0, int b = 0): x(a), y(b) {}
	int x;
	int y;
};


static vector<bool> visited;
int distance_square(Point p1, Point p2);
bool escape(Point curr, std::vector<Point> &crocodiles, int jump_distance );
bool able_to_jump_to_bank(Point curr, int jump_distance);


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int crocodiles_num, jump_distance;
	cin >> crocodiles_num >> jump_distance;
	std::vector<Point> crocodiles ;
	for (int i = 0; i < crocodiles_num; i++) {
		Point point;
		cin >> point.x >> point.y;
		crocodiles.push_back(point);
		visited.push_back(false);
	}
	Point origin(0, 0);
	bool escaped = false;
	for (int i = 0; i < crocodiles_num; i++) {
		if ( !visited[i] &&  distance_square(crocodiles[i], origin) <= (7.5 + jump_distance) * (7.5 + jump_distance)) {
			visited[i] = true;
			if (escape(crocodiles[i], crocodiles, jump_distance)) {
				escaped = true;
				break;
			}
		}

	}
	if (escaped)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;


	// cout << endl;
	// system("pause");
	// fclose(stdin);
	// fclose(stdout);
	return 0;
}
int distance_square(Point p1, Point p2) {
	return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

bool able_to_jump_to_bank(Point curr, int jump_distance) {
	return curr.x + jump_distance >= 50 || curr.x - jump_distance <= -50 || curr.y + jump_distance >= 50 || curr.y - jump_distance <= -50 ;
}


bool escape(Point curr, std::vector<Point> &crocodiles , int jump_distance) {
	if (able_to_jump_to_bank(curr, jump_distance))
		return true;
	else {
		for (int i = 0; i < static_cast<int>(crocodiles.size()) ; i++)
			if (!visited[i] && distance_square(curr, crocodiles[i]) <= jump_distance * jump_distance) {
				visited[i] = true;
				if (escape(crocodiles[i], crocodiles, jump_distance))
					return true;
			}

	}
	return false;
}

/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 Saving_James_Bond_Hard_Version.cpp
* @version:
* @Time: 		 2015-09-09 20:50:39
* @Description:	 07-图5 Saving James Bond - Hard Version   (30分)
*
+----------------------------------------------------------
*/
#include <iostream>
#include <vector>
#include <climits>


using namespace std;

struct Point
{
	Point(int a = 0, int b = 0): x(a), y(b) {}
	int x;
	int y;
	friend ostream& operator<<(ostream& os, const Point& point);
};

const Point origin(0, 0);


ostream& operator<<(ostream& os, const Point& point) {
	os << point.x << " " << point.y;
	return os;
}

static vector<bool> visited;
int distance_square(Point p1, Point p2);
void escape(int curr, std::vector<Point> &crocodiles, int jump_distance, int curr_setp, vector<int>&curr_Path , int &min_step, vector<int>& min_Path );
bool able_to_jump_to_bank(Point curr, int jump_distance);


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int crocodiles_num, jump_distance;
	cin >> crocodiles_num >> jump_distance;
	std::vector<Point> crocodiles ;
	visited.push_back(false);
	crocodiles.push_back(origin);//0 is origin   1~n is the crocodiles

	for (int i = 1; i <= crocodiles_num; i++) {
		Point point;
		cin >> point.x >> point.y;
		crocodiles.push_back(point);
		visited.push_back(false);
	}


	vector<int> curr_Path;
	int min_step = INT_MAX;
	vector<int> min_Path;
	if (7.5 + jump_distance >= 50) {//the bound situation
		min_step = 1;
	}
	for (int i = 1; i <= crocodiles_num; i++) {
		if ( !visited[i] &&  1.0 * distance_square(crocodiles[i], origin) <= (7.5 + jump_distance) * (7.5 + jump_distance)) {
			curr_Path.push_back(i);
			visited[i] = true;
			escape(i, crocodiles, jump_distance, 1, curr_Path, min_step, min_Path);
			curr_Path.clear();
		}

	}
	if (min_step != INT_MAX) {
		cout << min_step << endl;
		for (int k : min_Path)
			cout << crocodiles[k] << endl;
	}
	else
		cout << "0" << endl;


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


void escape(int curr, std::vector<Point> &crocodiles, int jump_distance, int curr_setp, vector<int>&curr_Path , int &min_step, vector<int>& min_Path ) {

	if (able_to_jump_to_bank(crocodiles[curr] , jump_distance)) {
		curr_setp++;
		// cout << "-----------able_to_jump_to_bank----------" << endl;
		if (curr_setp < min_step || (curr_setp == min_step && distance_square(crocodiles[curr_Path[0]], origin) < distance_square(crocodiles[min_Path[0]], origin))) {
			min_step = curr_setp;
			min_Path = curr_Path;
		}
		// cout << "min_step : " << min_step << endl;
		// cout << "min_Path : ";
		// for (int k : min_Path)
		// 	cout << "( " << crocodiles[k] << " )" << ends;
		// cout << endl;
		// cout << "-----------------------------------------" << endl;
	}
	else {
		for (int i = 1; i < static_cast<int>(crocodiles.size()) ; i++)
			if (!visited[i] && distance_square(crocodiles[curr] , crocodiles[i]) <= jump_distance * jump_distance) {
				// cout << "curr point : " << crocodiles[curr] << endl;
				curr_setp++;
				// cout << "curr_setp : " << curr_setp << endl;
				curr_Path.push_back(i);
				// cout << "curr_Path : ";
				// for (int k : curr_Path)
				// cout << "(" << crocodiles[k] << " )" << ends;
				// cout << endl;
				// system("pause");

				visited[i] = true;
				escape(i, crocodiles, jump_distance, curr_setp, curr_Path, min_step, min_Path);
				curr_Path.pop_back();
				curr_setp--;
				visited[i] = false;
			}

	}
}

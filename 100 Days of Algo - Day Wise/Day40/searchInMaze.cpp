#include<bits/stdc++.h>
using namespace std;

typedef enum {white,black} color;

struct Coordinate {
	bool operator==(const Coordinate& that) const {
		return x == that.x && y == that.y;
	}
	int x, y;
};

//Check cur is within maze and is a white pixel
bool isFeasible(const Coordinate& cur, const vector<vector<color>>& maze) {
	return (cur.x >= 0 && cur.x < maze.size() && cur.y >= 0 && cur.y < maze[cur.x].size() && maze[cur.x][cur.y] == white);
}

//Perform DFS to find a feasible path
bool SearchMazeHelper(const Coordinate& cur, const Coordinate& e, vector<vector<color>>* maze, vector<Coordinate>* path) {
	if (cur == e)
		return true;
	const vector<vector<int>> shiftOp = { {0,1},{0,-1},{1,0},{-1,0} };
	for (const vector<int>& s : shiftOp) {
		Coordinate next{ cur.x + s[0],cur.y + s[1] };
		if (isFeasible(next, *maze)) {
			(*maze)[next.x][next.y] = black;
			path->emplace_back(next);
			if (SearchMazeHelper(next, e, maze, path))
				return true;
			path->pop_back();
		}
	}
	return false;
}

vector<Coordinate> SearchMaze(vector<vector<color>>& maze, const Coordinate& s, const Coordinate& e) {
	vector<Coordinate> path;
	maze[s.x][s.y] = black;
	path.emplace_back(s);
	if (!SearchMazeHelper(s, e, &maze, &path))
		path.pop_back(); //Empty path implies no path between s and e
	return path;
}

int main() {
	vector<vector<color>> maze = { {black,white,white,white,white},
								   {white,black,black,white,white},
								   {white,black,black,white,white},
								   {white,white,white,white,white},
								   {white,white,black,white,white} };
	const Coordinate s = { 4,0 };
	const Coordinate e = { 0,4 };
	vector<Coordinate> path= SearchMaze(maze, s, e);
	for (int i = 0; i < path.size(); i++)
		cout << path[i].x<<" "<<path[i].y<<"\n";
	return 0;
}
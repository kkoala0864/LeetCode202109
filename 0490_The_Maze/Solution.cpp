#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

bool dfs(vector<vector<int>>& maze, int x, int y, vector<int>& destination, vector<vector<int>>& visited) {
	if (x == destination[0] && y == destination[1]) return true;
	if (visited[x][y]) return false;

	visited[x][y] = true;

	int nx = x;
	while (nx - 1 >= 0 && maze[nx - 1][y] == 0) --nx;
	if (!visited[nx][y]) {
		if (dfs(maze, nx, y, destination, visited)) return true;
	}

	nx = x;
	while (nx + 1 < maze.size() && maze[nx + 1][y] == 0) ++nx;
	if (!visited[nx][y]) {
		if (dfs(maze, nx, y, destination, visited)) return true;
	}

	int ny = y;
	while (ny - 1 >= 0 && maze[x][ny - 1] == 0) --ny;
	if (!visited[x][ny]) {
		if (dfs(maze, x, ny, destination, visited)) return true;
	}

	ny = y;
	while (ny + 1 < maze[0].size() && maze[x][ny + 1] == 0) ++ny;
	if (!visited[x][ny]) {
		if (dfs(maze, x, ny, destination, visited)) return true;
	}

	return false;
}

bool Solution::hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
	int m = maze.size();
	int n = maze[0].size();

	vector<vector<int>> visited(m, vector<int>(n, false));
	return dfs(maze, start[0], start[1], destination, visited);
}

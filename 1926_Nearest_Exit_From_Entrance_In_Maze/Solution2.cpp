#include <Solution.h>
#include <iostream>
#include <queue>

using std::pair;
using std::queue;

int Solution::nearestExit2(vector<vector<char>>& maze, vector<int>& entrance) {
	int m = maze.size();
	int n = maze[0].size();

	for (int i = 0 ; i < m ; ++i) {
		if (maze[i][0] == '.') maze[i][0] = '*';
		if (maze[i][n-1] == '.') maze[i][n-1] = '*';
	}
	for (int j = 0 ; j < n ; ++j) {
		if (maze[0][j] == '.') maze[0][j] = '*';
		if (maze[m-1][j] == '.') maze[m-1][j] = '*';
	}

	queue<pair<int, int>> que, next;
	int result = 0;
	vector<int> dir = {1, 0, -1, 0, 1};
	que.emplace(pair<int, int>(entrance[0], entrance[1]));
	maze[entrance[0]][entrance[1]] = '+';

	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		if (maze[x][y] == '*') return result;

		for (int i = 0 ; i < 4 ; ++i) {
			int nx = x + dir[i];
			int ny = y + dir[i+1];
			if (nx >= m || ny >= n || nx < 0 || ny < 0 || maze[nx][ny] == '+') continue;
			if (maze[nx][ny] == '.') maze[nx][ny] = '+';
			next.emplace(pair<int, int>(nx, ny));
		}

		if (que.empty()) {
			que = move(next);
			++result;
		}
	}
	return -1;
}


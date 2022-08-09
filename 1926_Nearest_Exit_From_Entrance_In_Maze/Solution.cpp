#include <Solution.h>
#include <iostream>
#include <queue>

using std::queue;
using std::pair;
using std::cout;
using std::endl;

int Solution::nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
	int m = maze.size();
	int n = maze[0].size();
	maze[entrance[0]][entrance[1]] = '-';

	queue<pair<int, int>> que, next;
	for (int i = 0 ; i < m ; ++i) {
		if (maze[i][0] == '.') que.emplace(pair<int, int>(i, 0));
		if (maze[i][n-1] == '.') que.emplace(pair<int, int>(i, n-1));
	}

	for (int i = 0 ; i < n ; ++i) {
		if (maze[0][i] == '.') que.emplace(pair<int, int>(0, i));
		if (maze[m-1][i] == '.') que.emplace(pair<int, int>(m-1, i));
	}


	vector<int> axis = {1, 0, -1, 0, 1};
	int result = 0;
	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		if (x == entrance[0] && y == entrance[1]) return result;
		cout <<x << " : "<< y << endl;

		que.pop();
		for (int i = 0 ; i < 4 ; ++i) {
			int nx = x + axis[i];
			int ny = y + axis[i+1];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n || maze[nx][ny] == '+') continue;
			maze[nx][ny] = '+';
			next.emplace(pair<int, int>(nx, ny));
		}

		if (que.empty()) {
			++result;
			que = move(next);
		}
	}
	return -1;
}


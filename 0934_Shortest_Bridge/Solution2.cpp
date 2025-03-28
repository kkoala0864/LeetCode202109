#include <Solution.h>
#include <iostream>
#include <queue>

using std::cout;
using std::endl;
using std::pair;
using std::queue;

const vector<int> dir = {1, 0, -1, 0, 1};

void dfs(int x, int y, vector<vector<int>> &g, queue<pair<int, int>> &que) {
	if (g[x][y] == 0)
		return;

	g[x][y] = 2;
	que.emplace(pair<int, int>(x, y));
	for (int i = 0; i < 4; ++i) {
		int nx = x + dir[i];
		int ny = y + dir[i + 1];
		if (nx < 0 || ny < 0 || nx >= g.size() || ny >= g[0].size() || g[nx][ny] == 0 || g[nx][ny] == 2)
			continue;
		dfs(nx, ny, g, que);
	}
}

int Solution::shortestBridge2(vector<vector<int>> &grid) {
	int m = grid.size();
	int n = grid[0].size();
	queue<pair<int, int>> que, next;

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (grid[i][j] == 0)
				continue;
			dfs(i, j, grid, que);
			break;
		}
		if (!que.empty())
			break;
	}

	int result = 0;
	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();

		if (grid[x][y] == 1)
			return result - 1;
		for (int i = 0; i < 4; ++i) {
			int nx = x + dir[i];
			int ny = y + dir[i + 1];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] == 2)
				continue;
			if (grid[nx][ny] == 0)
				grid[nx][ny] = 2;
			next.emplace(pair<int, int>(nx, ny));
		}

		if (que.empty()) {
			que = move(next);
			++result;
		}
	}
	return -1;
}

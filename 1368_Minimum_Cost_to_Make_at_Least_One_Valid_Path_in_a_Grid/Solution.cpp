#include <Solution.h>
#include <iostream>
#include <queue>

using std::pair;
using std::queue;

vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(const vector<vector<int>> &grid, vector<vector<int>> &cost, int x, int y, int level, queue<pair<int, int>> &next) {
	int m = grid.size();
	int n = grid[0].size();
	if (x < 0 || y < 0 || x >= m || y >= n || cost[x][y] != INT_MAX)
		return;

	cost[x][y] = level;
	next.emplace(pair<int, int>(x, y));

	int nd = grid[x][y] - 1;
	int nx = x + dir[nd].first;
	int ny = y + dir[nd].second;
	if (nx < 0 || ny < 0 || nx >= m || ny >= n || cost[nx][ny] != INT_MAX)
		return;
	dfs(grid, cost, nx, ny, level, next);
}

int Solution::minCost(vector<vector<int>> &grid) {
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<int>> cost(m, vector<int>(n, INT_MAX));

	queue<pair<int, int>> que, next;
	dfs(grid, cost, 0, 0, 0, que);

	int level = 1;
	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();

		for (int i = 0; i < 4; ++i) {
			if (i == (grid[x][y] - 1))
				continue;
			int nx = x + dir[i].first;
			int ny = y + dir[i].second;
			dfs(grid, cost, nx, ny, level, next);
		}

		if (que.empty()) {
			++level;
			que = move(next);
		}
	}
	return cost[m - 1][n - 1];
}

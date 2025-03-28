#include <Solution.h>
#include <iostream>
#include <queue>

using std::pair;
using std::queue;

vector<int> axis = {1, 0, -1, 0, 1};

void dfs(vector<vector<int>> &grid, int x, int y, int cnt, queue<pair<int, int>> &q) {
	grid[x][y] = cnt;

	q.emplace(pair<int, int>(x, y));

	for (int i = 0; i < 4; ++i) {
		int nx = x + axis[i];
		int ny = y + axis[i + 1];
		if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size() || grid[nx][ny] != 1)
			continue;
		dfs(grid, nx, ny, cnt, q);
	}
}

int Solution::shortestBridge(vector<vector<int>> &grid) {
	int cnt = 2;
	queue<pair<int, int>> q1, q2;
	for (int i = 0; i < grid.size(); ++i) {
		for (int j = 0; j < grid[0].size(); ++j) {
			if (grid[i][j] == 1) {
				dfs(grid, i, j, cnt++, q1.empty() ? q1 : q2);
			}
		}
	}

	int result = 0;
	queue<pair<int, int>> q = q1.size() < q2.size() ? q1 : q2, next;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = x + axis[i];
			int ny = y + axis[i + 1];
			if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size() || grid[x][y] == grid[nx][ny])
				continue;
			if (grid[nx][ny] == 0) {
				grid[nx][ny] = grid[x][y];
				next.emplace(pair<int, int>(nx, ny));
			} else {
				return result;
			}
		}

		if (q.empty()) {
			++result;
			q = move(next);
		}
	}
	return result;
}

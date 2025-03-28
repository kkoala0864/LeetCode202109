#include <Solution.h>
#include <iostream>
#include <queue>
#include <algorithm>

using std::max;
using std::pair;
using std::queue;

int Solution::maxDistance(vector<vector<int>> &grid) {
	queue<pair<int, int>> que;
	int m = grid.size();
	int n = grid[0].size();

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (grid[i][j] == 1)
				que.emplace(pair<int, int>(i, j));
		}
	}

	vector<int> axis = {1, 0, -1, 0, 1};
	int result = 0;
	while (!que.empty()) {
		auto cur = que.front();
		que.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = cur.first + axis[i];
			int ny = cur.second + axis[i + 1];

			if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 0)
				continue;

			grid[nx][ny] = grid[cur.first][cur.second] + 1;
			que.emplace(pair<int, int>(nx, ny));

			result = max(result, grid[nx][ny]);
		}
	}
	return result == 0 ? -1 : result - 1;
}

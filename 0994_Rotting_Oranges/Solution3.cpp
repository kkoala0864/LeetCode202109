#include <Solution.h>
#include <iostream>
#include <queue>

using std::queue;

int Solution::orangesRotting3(vector<vector<int>> &grid) {
	int m = grid.size();
	int n = grid[0].size();
	int result = 0;
	int freshCnt = 0;
	queue<int> que, next;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (grid[i][j] == 2) {
				que.emplace(i * n + j);
			} else if (grid[i][j] == 1) {
				++freshCnt;
			}
		}
	}
	if (freshCnt == 0)
		return 0;

	vector<int> axis = {1, 0, -1, 0, 1};
	while (!que.empty()) {
		int x = que.front() / n;
		int y = que.front() % n;
		que.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = x + axis[i];
			int ny = y + axis[i + 1];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1)
				continue;
			--freshCnt;
			grid[nx][ny] = 2;
			next.emplace(nx * n + ny);
		}

		if (que.empty()) {
			++result;
			que = move(next);
		}
	}
	return freshCnt == 0 ? result - 1 : -1;
}

#include <Solution.h>
#include <iostream>
#include <queue>

using std::pair;
using std::queue;

int Solution::orangesRotting2(vector<vector<int>> &grid) {
	queue<pair<int, int>> que, next;
	int cnt = 0;

	for (int i = 0; i < grid.size(); ++i) {
		for (int j = 0; j < grid[0].size(); ++j) {
			if (grid[i][j] == 2)
				que.emplace(pair<int, int>(i, j));
			if (grid[i][j] == 1)
				++cnt;
		}
	}

	if (cnt == 0)
		return 0;
	int result = 0;
	vector<int> axis = {1, 0, -1, 0, 1};

	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;

		que.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + axis[i];
			int ny = y + axis[i + 1];
			if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size() || grid[nx][ny] != 1)
				continue;
			grid[nx][ny] = 2;
			--cnt;
			next.emplace(pair<int, int>(nx, ny));
		}

		if (que.empty()) {
			++result;
			que = move(next);
		}
	}

	return cnt == 0 ? result - 1 : -1;
}

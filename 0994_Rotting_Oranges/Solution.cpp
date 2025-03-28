#include <Solution.h>
#include <iostream>
#include <queue>

using std::cout;
using std::endl;
using std::queue;

int Solution::orangesRotting(vector<vector<int>> &grid) {
	int fresh_cnt = 0;
	int minute_cnt = 0;
	int m = grid.size();
	int n = grid[0].size();
	queue<vector<int>> cur;
	queue<vector<int>> next;

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (grid[i][j] == 2) {
				cur.push({i, j});
			} else if (grid[i][j] == 1) {
				++fresh_cnt;
			}
		}
	}

	if (cur.empty() && fresh_cnt == 0)
		return 0;
	vector<vector<int>> axis = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	while (!cur.empty()) {
		vector<int> loc = cur.front();
		cur.pop();

		for (const auto &ai : axis) {
			int x = loc[0] + ai[0];
			int y = loc[1] + ai[1];
			if (x < 0 || y < 0 || x >= m || y >= n)
				continue;
			if (grid[x][y] == 1) {
				grid[x][y] = 2;
				next.push({x, y});
				--fresh_cnt;
			}
		}

		if (cur.empty()) {
			++minute_cnt;
			cur = move(next);
		}
	}

	return fresh_cnt == 0 ? minute_cnt - 1 : -1;
}

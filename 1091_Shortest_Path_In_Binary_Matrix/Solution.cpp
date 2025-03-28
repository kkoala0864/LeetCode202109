#include <Solution.h>
#include <iostream>
#include <queue>

using std::pair;
using std::queue;

int Solution::shortestPathBinaryMatrix(vector<vector<int>> &grid) {
	int n = grid.size();
	int result = 1;
	vector<pair<int, int>> dir = {{0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}};

	queue<pair<int, int>> que, next;
	que.push({0, 0});
	while (!que.empty()) {
		auto cur = que.front();
		que.pop();

		if (cur.first == n - 1 && cur.second == n - 1)
			return result;
		if (grid[cur.first][cur.second] == 0) {
			grid[cur.first][cur.second] = 1;
			for (const auto &d : dir) {
				int x = cur.first + d.first;
				int y = cur.second + d.second;
				if (x >= 0 && y >= 0 && x < n && y < n && grid[x][y] == 0) {
					next.push({x, y});
				}
			}
		}

		if (que.empty()) {
			++result;
			que = move(next);
		}
	}
	return -1;
}

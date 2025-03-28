#include <Solution.h>
#include <iostream>
#include <queue>
#include <vector>

using std::pair;
using std::queue;
using std::vector;

int Solution::minKnightMoves(int x, int y) {
	if (x == 0 && y == 0)
		return 0;
	vector<pair<int, int>> dirs = {{1, 2}, {2, 1}, {-1, 2}, {2, -1}, {-2, 1}, {1, -2}, {-1, -2}, {-2, -1}};
	vector<vector<bool>> visited(601, vector<bool>(601, false));
	queue<pair<int, int>> que, next;

	que.push({0, 0});
	visited[300][300] = true;

	int result = 1;
	while (!que.empty()) {
		pair<int, int> cur = que.front();
		que.pop();

		for (const auto &dir : dirs) {
			int i = cur.first + dir.first;
			int j = cur.second + dir.second;
			if (visited[i + 300][j + 300])
				continue;

			if (i == x && j == y)
				return result;
			next.push({i, j});
			visited[i + 300][j + 300] = true;
		}

		if (que.empty()) {
			++result;
			que = move(next);
		}
	}
	return -1;
}

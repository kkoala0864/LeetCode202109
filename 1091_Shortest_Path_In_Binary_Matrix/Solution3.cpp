#include <Solution.h>
#include <iostream>
#include <queue>

using std::pair;
using std::queue;

int Solution::shortestPathBinaryMatrix3(vector<vector<int>>& grid) {
	if (grid[0][0] == 1) return -1;
	queue<pair<int, int>> que, next;

	int result = 0;

	que.emplace(pair<int, int>(0, 0));
	vector<int> dir = {1, 0, -1, 0, 1, -1, -1, 1, 1};
	grid[0][0] = 1;

	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();

		if (x == grid.size() - 1 && y == grid[0].size() - 1) return result + 1;

		for (int i = 0 ; i < 8 ; ++i) {
			int nx = x + dir[i];
			int ny = y + dir[i+1];
			if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size() || grid[nx][ny] == 1) continue;
			grid[nx][ny] = 1;
			next.emplace(pair<int, int>(nx, ny));
		}
		if (que.empty()) {
			que = move(next);
			++result;
		}
	}
	return -1;
}


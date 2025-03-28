#include <Solution.h>
#include <iostream>
#include <queue>

using std::pair;
using std::queue;

int Solution::getFood(vector<vector<char>> &grid) {
	int m = grid.size();
	int n = grid[0].size();

	queue<pair<int, int>> que, next;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (grid[i][j] == '*') {
				que.emplace(pair<int, int>(i, j));
				grid[i][j] = 'X';
				break;
			}
		}
		if (!que.empty())
			break;
	}
	int result = 0;

	vector<int> dir = {1, 0, -1, 0, 1};
	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = x + dir[i];
			int ny = y + dir[i + 1];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] == 'X')
				continue;
			if (grid[nx][ny] == '#')
				return result + 1;
			grid[nx][ny] = 'X';
			next.emplace(pair<int, int>(nx, ny));
		}
		if (que.empty()) {
			++result;
			que = move(next);
		}
	}
	return -1;
}

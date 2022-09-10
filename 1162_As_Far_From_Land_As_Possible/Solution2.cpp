#include <Solution.h>
#include <iostream>
#include <queue>
#include <algorithm>

using std::max;
using std::queue;
using std::pair;

int Solution::maxDistance2(vector<vector<int>>& grid) {
	int m = grid.size();
	int n = grid[0].size();

	queue<int> que;
	for (int i = 0 ; i < grid.size() ; ++i) {
		for (int j = 0 ; j < grid[0].size() ; ++j) {
			if (grid[i][j]) {
				que.emplace(i * n + j);
			}
		}
	}
	if (que.empty()) return -1;
	vector<int> axis = {1, 0, -1, 0, 1};
	int result = 0;
	while (!que.empty()) {
		int x = que.front() / n;
		int y = que.front() % n;
		que.pop();

		for (int i = 0 ; i < 4 ; ++i) {
			int nx = x + axis[i];
			int ny = y + axis[i+1];

			if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 0) continue;
			grid[nx][ny] = grid[x][y] + 1;
			result = max(result, grid[nx][ny]);
			que.emplace(nx * n + ny);
		}
	}
	return result - 1;
}

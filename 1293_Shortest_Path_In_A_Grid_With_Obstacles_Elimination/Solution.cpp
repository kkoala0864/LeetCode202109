#include <Solution.h>
#include <iostream>
#include <queue>
#include <algorithm>

using std::pair;
using std::queue;
using std::min;

int Solution::shortestPath(vector<vector<int>>& grid, int k) {
	int m = grid.size();
	int n = grid[0].size();

	vector<vector<vector<int>>> minStep(m, vector<vector<int>>(n, vector<int>(k + 1, INT_MAX)));
	queue<pair<int, int>> que;

	minStep[0][0][0] = 0;
	vector<int> dir = {1, 0, -1, 0, 1};
	que.emplace(pair<int, int>(0, 0));

	while (!que.empty()) {
		int x = que.front().first / n;
		int y = que.front().first % n;
		int curK = que.front().second;
		que.pop();


		for (int i = 0 ; i < 4 ; ++i) {
			int nx = x + dir[i];
			int ny = y + dir[i+1];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
			if (grid[nx][ny] == 1) {
				if (curK < k) {
					if (minStep[nx][ny][curK+1] > minStep[x][y][curK] + 1) {
						minStep[nx][ny][curK+1] = minStep[x][y][curK] + 1;
						que.emplace(pair<int, int>(nx * n + ny, curK + 1));
					}
				}
			} else {
				if (minStep[nx][ny][curK] > minStep[x][y][curK] + 1) {
					minStep[nx][ny][curK] = minStep[x][y][curK] + 1;
					que.emplace(pair<int, int>(nx * n + ny, curK));
				}
			}

		}
	}
	int result = INT_MAX;
	for (int i = 0 ; i <= k ; ++i) {
		result = min(minStep[m-1][n-1][i], result);
	}
	return result == INT_MAX ? -1 : result;
}

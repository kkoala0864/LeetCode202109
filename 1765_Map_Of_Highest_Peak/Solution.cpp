#include <Solution.h>
#include <iostream>
#include <queue>
#include <climits>

using std::pair;
using std::queue;

vector<vector<int>> Solution::highestPeak(vector<vector<int>> &isWater) {
	int m = isWater.size();
	int n = isWater[0].size();

	queue<pair<int, int>> que;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (isWater[i][j]) {
				que.emplace(pair<int, int>(i, j));
			}
			isWater[i][j] = isWater[i][j] == 1 ? 0 : INT_MAX;
		}
	}

	vector<int> dir = {1, 0, -1, 0, 1};
	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = x + dir[i];
			int ny = y + dir[i + 1];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n || isWater[nx][ny] != INT_MAX)
				continue;
			isWater[nx][ny] = isWater[x][y] + 1;
			que.emplace(pair<int, int>(nx, ny));
		}
	}
	return isWater;
}

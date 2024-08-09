#include <Solution.h>
#include <iostream>
#include <queue>

using std::queue;
using std::pair;

vector<vector<int>> Solution::highestPeak(vector<vector<int>>& isWater) {
	vector<vector<int>> result = isWater;
	queue<pair<int, int>> que;

	for (int i = 0 ; i < isWater.size() ; ++i) {
		for (int j = 0 ; j < isWater[0].size() ; ++j) {
			if (isWater[i][j] == 0) continue;
			que.emplace(pair<int, int>(i, j));
			result[i][j] = 0;
		}
	}

	vector<int> dir = {1, 0, -1, 0, 1};
	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();

		for (int i = 0 ; i < 4 ; ++i) {
			int nx = x + dir[i];
			int ny = y + dir[i+1];
			if (nx < 0 || ny < 0 || nx >= isWater.size() || ny >= isWater[0].size() || result[nx][ny] != 0 || isWater[nx][ny] == 1) continue;
			result[nx][ny] = result[x][y] + 1;
			que.emplace(pair<int, int>(nx, ny));
		}
	}
	return result;
}

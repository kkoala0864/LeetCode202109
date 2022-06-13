#include <Solution.h>
#include <iostream>
#include <queue>
#include <algorithm>

using std::queue;
using std::pair;
using std::min;

int Solution::shortestDistance(vector<vector<int>>& grid) {
	vector<pair<int, int>> houses;

	for (int i = 0 ; i < grid.size() ; ++i) {
		for (int j = 0 ; j < grid[0].size() ; ++j) {
			if (grid[i][j] == 1) houses.push_back({i, j});
			if (grid[i][j] != 0) grid[i][j] = INT_MAX;
		}
	}

	vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
	vector<int> dir = {1, 0, -1, 0, 1};
	for (int hIdx = 0 ; hIdx < houses.size() ; ++hIdx) {
		int cnt = 1;
		queue<pair<int, int>> que, next;
		que.push(houses[hIdx]);

		while (!que.empty()) {
			auto cur = que.front();
			que.pop();

			for (int i = 0 ; i < 4 ; ++i) {
				int nx = cur.first + dir[i];
				int ny = cur.second + dir[i+1];
				if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size() || grid[nx][ny] == INT_MAX || visited[nx][ny] != hIdx) continue;
				next.push({nx, ny});
				++visited[nx][ny];
				grid[nx][ny] += cnt;
			}

			if (que.empty()) {
				que = move(next);
				++cnt;
			}
		}
	}

	int result = INT_MAX;
	for (int i = 0 ; i < grid.size() ; ++i) {
		for (int j = 0 ; j < grid[0].size() ; ++j) {
			if (visited[i][j] == houses.size()) result = min(result, grid[i][j]);
		}
	}
	return result == INT_MAX ? -1 : result;
}

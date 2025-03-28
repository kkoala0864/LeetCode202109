#include <Solution.h>
#include <iostream>
#include <queue>
#include <algorithm>

using std::cout;
using std::endl;
using std::max;
using std::min;
using std::pair;
using std::priority_queue;
using std::queue;

vector<int> dir = {1, 0, -1, 0, 1};

void getSF(vector<vector<int>> &grid, vector<vector<int>> &sf) {
	int m = grid.size();
	int n = grid[0].size();

	queue<pair<int, int>> que;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (grid[i][j] == 0)
				continue;
			sf[i][j] = 0;
			que.emplace(pair<int, int>(i, j));
		}
	}

	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = x + dir[i];
			int ny = y + dir[i + 1];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n || sf[nx][ny] <= (sf[x][y] + 1))
				continue;
			sf[nx][ny] = sf[x][y] + 1;
			que.emplace(pair<int, int>(nx, ny));
		}
	}
}

int Solution::maximumSafenessFactor(vector<vector<int>> &grid) {
	if (grid[0][0] == 1 || grid.back().back() == 1)
		return 0;

	vector<vector<int>> sf(grid.size(), vector<int>(grid[0].size(), INT_MAX));
	getSF(grid, sf);

	priority_queue<vector<int>> pq;
	pq.push({sf[0][0], 0, 0});

	int result = INT_MAX;
	while (!pq.empty()) {
		int factor = pq.top()[0];
		int x = pq.top()[1];
		int y = pq.top()[2];
		pq.pop();

		result = min(result, factor);
		if (x == sf.size() - 1 && y == sf[0].size() - 1)
			return result;
		for (int i = 0; i < 4; ++i) {
			int nx = x + dir[i];
			int ny = y + dir[i + 1];
			if (nx < 0 || ny < 0 || nx >= sf.size() || ny >= sf[0].size() || sf[nx][ny] == 0)
				continue;
			pq.push({sf[nx][ny], nx, ny});
			sf[nx][ny] = 0;
		}
	}
	return 0;
}

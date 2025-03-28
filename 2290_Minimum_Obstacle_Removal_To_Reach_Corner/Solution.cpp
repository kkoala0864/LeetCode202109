#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
#include <tuple>

using std::min;
using std::pair;
using std::priority_queue;
using std::queue;
using std::tuple;

int Solution::Dijkstra(vector<vector<int>> &grid) {
	int m = grid.size(), n = grid[0].size();
	vector<vector<int>> cnt(m, vector<int>(n, INT_MAX));
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, std::greater<tuple<int, int, int>>> pq;

	cnt[0][0] = 0;
	pq.push({grid[0][0], 0, 0});
	vector<int> axis = {-1, 0, 1, 0, -1};
	while (!pq.empty()) {
		auto [c, i, j] = pq.top();
		pq.pop();

		for (int k = 0; k < 4; ++k) {
			int x = i + axis[k];
			int y = j + axis[k + 1];
			if (x < 0 || y < 0 || x >= m || y >= n)
				continue;
			int cost = c + grid[x][y];
			if (cnt[x][y] <= cost)
				continue;
			cnt[x][y] = cost;
			pq.push({cost, x, y});
		}
	}
	return cnt[m - 1][n - 1];
}

// BFS
int Solution::minimumObstacles(vector<vector<int>> &grid) {
	queue<pair<int, int>> que;
	int m = grid.size(), n = grid[0].size();
	vector<vector<int>> cnt(m, vector<int>(n, INT_MAX));
	vector<int> axis = {-1, 0, 1, 0, -1};
	cnt[0][0] = 0;
	que.push({0, 0});

	while (!que.empty()) {
		pair<int, int> cur = que.front();
		que.pop();

		for (int i = 0; i < 4; ++i) {
			int x = cur.first + axis[i];
			int y = cur.second + axis[i + 1];
			if (x < 0 || y < 0 || x >= m || y >= n)
				continue;
			int nCnt = cnt[cur.first][cur.second] + grid[x][y];
			if (nCnt < cnt[x][y]) {
				cnt[x][y] = nCnt;
				que.push({x, y});
			}
		}
	}
	return cnt[m - 1][n - 1];
}

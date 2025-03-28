#include <Solution.h>
#include <iostream>
#include <queue>
#include <algorithm>

using std::pair;
using std::queue;
using std::sort;

vector<vector<int>> Solution::minScore(vector<vector<int>> &grid) {
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<int>> in(m, vector<int>(n, 0));
	vector<vector<vector<pair<int, int>>>> out(m, vector<vector<pair<int, int>>>(n, vector<pair<int, int>>()));

	for (int i = 0; i < m; ++i) {
		vector<pair<int, int>> tmp;
		for (int j = 0; j < n; ++j) {
			tmp.emplace_back(pair<int, int>(grid[i][j], j));
		}
		sort(tmp.begin(), tmp.end());
		for (int j = 0; j < n - 1; ++j) {
			out[i][tmp[j].second].emplace_back(pair<int, int>(i, tmp[j + 1].second));
			++in[i][tmp[j + 1].second];
		}
	}
	for (int j = 0; j < n; ++j) {
		vector<pair<int, int>> tmp;
		for (int i = 0; i < m; ++i) {
			tmp.emplace_back(pair<int, int>(grid[i][j], i));
		}
		sort(tmp.begin(), tmp.end());
		for (int i = 0; i < m - 1; ++i) {
			out[tmp[i].second][j].emplace_back(pair<int, int>(tmp[i + 1].second, j));
			++in[tmp[i + 1].second][j];
		}
	}

	queue<pair<int, int>> que, next;

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (in[i][j] == 0) {
				que.emplace(pair<int, int>(i, j));
			}
		}
	}

	int v = 1;
	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();

		grid[x][y] = v;
		for (auto &o : out[x][y]) {
			--in[o.first][o.second];
			if (in[o.first][o.second] == 0)
				next.emplace(o);
		}
		if (que.empty()) {
			que = move(next);
			++v;
		}
	}
	return grid;
}

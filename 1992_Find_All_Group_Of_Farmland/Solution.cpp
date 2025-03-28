#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
using std::min;

void dfs(vector<vector<int>> &land, int x, int y, vector<int> &cur) {
	land[x][y] = 0;
	cur[0] = min(cur[0], x);
	cur[1] = min(cur[1], y);
	cur[2] = max(cur[2], x);
	cur[3] = max(cur[3], y);

	vector<int> dir = {1, 0, -1, 0, 1};

	for (int i = 0; i < 4; ++i) {
		int nx = x + dir[i];
		int ny = y + dir[i + 1];
		if (nx < 0 || ny < 0 || nx >= land.size() || ny >= land[0].size() || land[nx][ny] != 1)
			continue;
		dfs(land, nx, ny, cur);
	}
}

vector<vector<int>> Solution::findFarmland(vector<vector<int>> &land) {
	vector<vector<int>> result;
	for (int i = 0; i < land.size(); ++i) {
		for (int j = 0; j < land[0].size(); ++j) {
			if (land[i][j] == 0)
				continue;
			vector<int> cur = {i, j, i, j};
			dfs(land, i, j, cur);
			result.emplace_back(cur);
		}
	}
	return result;
}

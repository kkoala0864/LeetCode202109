#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

void dfs(vector<vector<int>>& g, int x, int y, int gold, int& result) {
	gold += g[x][y];
	int cur = g[x][y];
	g[x][y] = 0;
	result = max(result, gold);

	vector<int> dir = {1, 0, -1, 0, 1};
	for (int i = 0 ; i < 4 ; ++i) {
		int nx = x + dir[i];
		int ny = y + dir[i+1];
		if (nx < 0 || ny < 0 || nx >= g.size() || ny >= g[0].size() || g[nx][ny] == 0) continue;
		dfs(g, nx, ny, gold, result);
	}
	g[x][y] = cur;
}

int Solution::getMaximumGold(vector<vector<int>>& grid) {
	int result = 0;

	for (int i = 0 ; i < grid.size() ; ++i) {
		for (int j = 0 ; j < grid[0].size() ; ++j) {
			if (grid[i][j] == 0) continue;
			dfs(grid, i, j, 0, result);
		}
	}
	return result;
}

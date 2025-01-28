#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int dfs(vector<vector<int>>& grid, int x, int y) {
	int ret = grid[x][y];
	grid[x][y] = 0;

	vector<int> dir = {1, 0, -1, 0, 1};
	for (int i = 0 ; i < 4 ; ++i) {
		int nx = x + dir[i];
		int ny = y + dir[i+1];
		if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size() || grid[nx][ny] == 0) continue;
		ret += dfs(grid, nx, ny);
	}
	return ret;
}

int Solution::findMaxFish(vector<vector<int>>& grid) {
	int result = 0;
	for (int i = 0 ; i < grid.size() ; ++i) {
		for (int j = 0 ; j < grid[0].size() ; ++j) {
			if (grid[i][j] == 0) continue;
			int v = dfs(grid, i, j);
			result = max(result, v);
		}
	}
	return result;
}

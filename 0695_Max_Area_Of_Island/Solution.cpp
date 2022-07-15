#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

vector<int> axis = {1, 0, -1, 0, 1};

void dfs(vector<vector<int>>& grid, int x, int y, int& local) {
	if (grid[x][y] != 1) return;
	++local;
	grid[x][y] = 2;

	for (int i = 0 ; i < 4 ; ++i) {
		int nx = x + axis[i];
		int ny = y + axis[i+1];
		if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size() || grid[nx][ny] != 1) continue;
		dfs(grid, nx, ny, local);
	}
}

int Solution::maxAreaOfIsland(vector<vector<int>>& grid) {
	int result = 0;

	for (int i = 0 ; i < grid.size() ; ++i) {
		for (int j = 0 ; j < grid[0].size() ; ++j) {
			int local = 0;
			if (grid[i][j] == 1) {
				dfs(grid, i, j, local);
				result = max(result, local);
			}
		}
	}
	return result;
}

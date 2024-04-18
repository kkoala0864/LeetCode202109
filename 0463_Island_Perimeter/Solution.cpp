#include <Solution.h>
#include <iostream>

void dfs(vector<vector<int>>& grid, int i, int j, int& result) {
	vector<int> dir = {1, 0, -1, 0, 1};
	grid[i][j] = 2;

	for (int d = 0 ; d < 4 ; ++d) {
		int nx = i + dir[d];
		int ny = j + dir[d+1];
		if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size() || grid[nx][ny] == 0) {
			++result;
			continue;
		}
		if (grid[nx][ny] == 1) {
			dfs(grid, nx, ny, result);
		}
	}
}

int Solution::islandPerimeter(vector<vector<int>>& grid) {
	int result = 0;
	for (int i = 0 ; i < grid.size() ; ++i) {
		for (int j = 0 ; j < grid[0].size() ; ++j) {
			if (grid[i][j] != 1) continue;
			dfs(grid, i, j, result);
			break;
		}
	}
	return result;
}

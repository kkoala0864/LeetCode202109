#include <Solution.h>
#include <iostream>

vector<int> ai = {1, 0, -1, 0, 1};

void dfs(vector<vector<char>>& grid, int i, int j) {
	grid[i][j] = '0';

	for (int d = 0 ; d < 4 ; ++d) {
		int nx = i + ai[d];
		int ny = j + ai[d+1];
		if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size() || grid[nx][ny] == '0') continue;
		dfs(grid, nx, ny);
	}
}

int Solution::numIslands3(vector<vector<char>>& grid) {
	int result = 0;
	for (int i = 0 ; i < grid.size() ; ++i) {
		for (int j = 0 ; j < grid[0].size() ; ++j) {
			if (grid[i][j] == '1') {
				++result;
				dfs(grid, i, j);
			}
		}
	}
	return result;
}

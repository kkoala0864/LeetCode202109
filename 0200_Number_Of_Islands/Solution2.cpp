#include <Solution.h>
#include <iostream>

vector<vector<int>> axis = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void render2(vector<vector<char>> &grid, int i, int j) {
	for (const auto &ai : axis) {
		int x = i + ai[0];
		int y = j + ai[1];
		if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == '1') {
			grid[x][y] = '0';
			render2(grid, x, y);
		}
	}
}

int Solution::numIslands2(vector<vector<char>> &grid) {
	int m = grid.size();
	int n = grid[0].size();
	int result = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (grid[i][j] == '1') {
				render2(grid, i, j);
				++result;
			}
		}
	}
	return result;
}

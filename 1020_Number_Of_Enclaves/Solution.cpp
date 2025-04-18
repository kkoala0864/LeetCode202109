#include <Solution.h>
#include <iostream>

vector<int> dir = {1, 0, -1, 0, 1};

void render(vector<vector<int>> &grid, int x, int y) {
	grid[x][y] = 0;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dir[i];
		int ny = y + dir[i + 1];
		if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size() || grid[nx][ny] == 0)
			continue;
		render(grid, nx, ny);
	}
}

int Solution::numEnclaves(vector<vector<int>> &grid) {
	int m = grid.size();
	int n = grid[0].size();
	for (int i = 0; i < m; ++i) {
		if (grid[i][0] == 1)
			render(grid, i, 0);
		if (grid[i][n - 1] == 1)
			render(grid, i, n - 1);
	}
	for (int i = 0; i < n; ++i) {
		if (grid[0][i] == 1)
			render(grid, 0, i);
		if (grid[m - 1][i] == 1)
			render(grid, m - 1, i);
	}

	int result = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j)
			if (grid[i][j] == 1)
				++result;
	}
	return result;
}

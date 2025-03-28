#include <Solution.h>
#include <iostream>

using std::pair;

void render(vector<vector<char>> &grid, int x, int y) {
	if (x >= grid.size() || x < 0 || y >= grid[0].size() || y < 0 || grid[x][y] == '0')
		return;
	grid[x][y] = '0';
	render(grid, x + 1, y);
	render(grid, x - 1, y);
	render(grid, x, y + 1);
	render(grid, x, y - 1);
}

int Solution::numIslands(vector<vector<char>> &grid) {
	int cnt = 0;
	for (int i = 0; i < grid.size(); ++i) {
		for (int j = 0; j < grid[0].size(); ++j) {
			if (grid[i][j] == '1') {
				++cnt;
				render(grid, i, j);
			}
		}
	}
	return cnt;
}

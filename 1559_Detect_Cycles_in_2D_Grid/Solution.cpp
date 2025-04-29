#include <Solution.h>

bool dfs(vector<vector<char>>& grid, int x, int y, int lx, int ly) {
	char ori = grid[x][y];
	grid[x][y] = '&';

	vector<int> dir = {1, 0, -1, 0, 1};

	for (int di = 0 ; di < 4 ; ++di) {
		int nx = x + dir[di];
		int ny = y + dir[di + 1];
		if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size() || (nx == lx && ny == ly)) continue;
		if (grid[nx][ny] == '&') return true;
		if (grid[nx][ny] != ori) continue;
		if (dfs(grid, nx, ny, x, y)) return true;
	}
	grid[x][y] = '#';
	return false;
}

bool Solution::containsCycle(vector<vector<char>>& grid) {
	for (int i = 0 ; i < grid.size() ; ++i) {
		for (int j = 0 ; j < grid[i].size() ; ++j) {
			if (grid[i][j] == '#') continue;
			if (dfs(grid, i, j, -1, -1)) return true;
		}
	}
	return false;
}

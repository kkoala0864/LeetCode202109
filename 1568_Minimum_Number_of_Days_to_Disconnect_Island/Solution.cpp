#include <Solution.h>

void dfs(vector<vector<int>>& grid, int x, int y) {
	grid[x][y] = 0;

	vector<int> dir = {1, 0, -1, 0, 1};
	for (int i = 0 ; i < 4 ; ++i) {
		int nx = x + dir[i];
		int ny = y + dir[i+1];
		if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size() || grid[nx][ny] == 0) continue;
		dfs(grid, nx, ny);
	}
}

int countIsland(vector<vector<int>> grid) {
	int m = grid.size();
	int n = grid[0].size();

	int cnt = 0;
	for (int i = 0 ; i < m ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			if (grid[i][j] == 0) continue;
			++cnt;
			if (cnt > 1) return 2;
			dfs(grid, i, j);
		}
	}
	return cnt;
}

int Solution::minDays(vector<vector<int>>& grid) {
	int m = grid.size();
	int n = grid[0].size();

	int cnt = countIsland(grid);
	if (cnt != 1) return 0;

	for (int i = 0 ; i < m ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			if (grid[i][j] == 0) continue;
			grid[i][j] = 0;
			cnt = countIsland(grid);
			if (cnt != 1) return 1;
			grid[i][j] = 1;
		}
	}
	return 2;
}

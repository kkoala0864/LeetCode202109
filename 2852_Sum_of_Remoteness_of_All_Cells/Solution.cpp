#include <Solution.h>
#include <iostream>

void dfs(vector<vector<int>>& grid, int x, int y, int& cnt, long long& sum) {
	vector<int> dir = {1, 0, -1, 0, 1};
	for (int i = 0 ; i < 4 ; ++i) {
		int nx = x + dir[i];
		int ny = y + dir[i+1];
		if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size() || grid[nx][ny] == -1) continue;
		sum += grid[nx][ny];
		grid[nx][ny] = -1;
		++cnt;
		dfs(grid, nx, ny, cnt, sum);
	}
}

long long Solution::sumRemoteness(vector<vector<int>>& grid) {
	int m = grid.size();
	int n = grid[0].size();
	long long total = 0;
	long long result = 0;

	for (int i = 0 ; i < m ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			if (grid[i][j] == -1) continue;
			total += grid[i][j];
		}
	}

	for (int i = 0 ; i < m ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			if (grid[i][j] == -1) continue;
			long long sum = grid[i][j];
			grid[i][j] = -1;
			int cnt = 1;
			dfs(grid, i, j, cnt, sum);
			result += ((total - sum) * cnt);
		}
	}
	return result;
}

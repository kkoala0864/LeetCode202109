#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using std::unordered_set;
using std::max;

int dfs(vector<vector<int>>& grid, int x, int y, int flag) {
	int m = grid.size();
	int n = grid[0].size();
	grid[x][y] = flag;

	vector<int> dir = {1, 0, -1, 0, 1};
	int s = 1;
	for (int i = 0 ; i < 4 ; ++i) {
		int nx = x + dir[i];
		int ny = y + dir[i+1];
		if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1) continue;
		s += dfs(grid, nx, ny, flag);
	}
	return s;
}

int Solution::largestIsland(vector<vector<int>>& grid) {
	int m = grid.size();
	int n = grid[0].size();

	vector<int> slist(2, 0);
	int result = 0;

	for (int i = 0 ; i < m ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			if (grid[i][j] != 1) continue;
			int s = dfs(grid, i, j, slist.size());
			result = max(result, s);
			slist.emplace_back(s);
		}
	}
	vector<int> dir = {1, 0, -1, 0, 1};
	for (int i = 0 ; i < m ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			if (grid[i][j] != 0) continue;
			unordered_set<int> us;
			int cs = 1;
			for (int di = 0 ; di < 4 ; ++di) {
				int nx = i + dir[di];
				int ny = j + dir[di+1];
				if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] < 2) continue;
				if (us.count(grid[nx][ny])) continue;
				cs += slist[grid[nx][ny]];
				us.emplace(grid[nx][ny]);
			}
			result = max(cs, result);
		}
	}
	return result;
}

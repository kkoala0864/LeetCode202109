#include <Solution.h>
#include <iostream>


// TC : O(3 ^ N) where N is total number of cell
// SC : O(N) : recursive stack space
vector<int> dir = {1, 0 ,-1, 0, 1};

void dfs(vector<vector<int>>& grid, int visited, int cur, int end, const int& m, const int& n, int& result) {
	if (cur == end) {
		if (visited == ((1 << (m * n)) - 1)) ++result;
		return;
	}

	int x = cur / n;
	int y = cur % n;
	for (int i = 0 ; i < 4 ; ++i) {
		int nx = x + dir[i];
		int ny = y + dir[i+1];
		if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
		int nIdx = nx * n + ny;
		if (visited & (1 << nIdx)) continue;

		int tmpVisited = visited | (1 << nIdx);
		dfs(grid, tmpVisited, nIdx, end, m, n, result);
	}
}

int Solution::uniquePathsIII(vector<vector<int>>& grid) {
	int visited = 0;
	int m = grid.size();
	int n = grid[0].size();

	int start = -1;
	int end = -1;
	int result = 0;
	for (int i = 0; i < m ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			if (grid[i][j] == -1) {
				visited |= 1 << (i * n + j);
			} else if (grid[i][j] == 1) {
				start = i * n + j;
				visited |= 1 << start;
			} else if (grid[i][j] == 2) {
				end = i * n + j;
			}
		}
	}

	dfs(grid, visited, start, end, m, n, result);
	return result;
}

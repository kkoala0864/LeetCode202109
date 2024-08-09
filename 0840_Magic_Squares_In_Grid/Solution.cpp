#include <Solution.h>
#include <iostream>

bool check(vector<vector<int>>& g, int x, int y) {
	if (x < 1 || y < 1 || x >= g.size() - 1 || y >= g[0].size() - 1) return false;
	vector<int> visited(9, false);
	vector<int> cSum(3, 0);

	for (int i = 0 ; i < 3 ; ++i) {
		int rSum = 0;
		for (int j = 0 ; j < 3 ; ++j) {
			int nx = x - 1 + i;
			int ny = y - 1 + j;

			if ((g[nx][ny] - 1) >= visited.size() || visited[g[nx][ny]-1]) return false;
			visited[g[nx][ny]-1] = true;
			rSum += g[nx][ny];
			cSum[j] += g[nx][ny];
		}
		if (rSum != 15) return false;
	}
	for (int i = 0 ; i < 3 ; ++i) {
		if (cSum[i] != 15) return false;
	}
	int ldSum = 0;
	int rdSum = 0;
	for (int i = 0 ; i < 3 ; ++i) {
		ldSum += g[x-1+i][y-1+i];
		rdSum += g[x-1+i][y+1-i];
	}
	return ldSum == 15 && rdSum == 15;
}

int Solution::numMagicSquaresInside(vector<vector<int>>& grid) {
	int result = 0;
	for (int i = 0 ; i < grid.size() ; ++i) {
		for (int j = 0 ; j < grid.size() ; ++j) {
			if (grid[i][j] != 5) continue;
			if (check(grid, i, j)) ++result;
		}
	}
	return result;
}

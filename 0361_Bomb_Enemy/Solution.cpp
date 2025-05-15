#include <Solution.h>

int Solution::maxKilledEnemies(vector<vector<char>> &grid) {
	int m = grid.size();
	int n = grid[0].size();

	vector<vector<int>> cnt(m, vector<int>(n, 0));

	for (int i = 0 ; i < m ; ++i) {
		int preCnt = 0;
		for (int j = 0 ; j < n ; ++j) {
			if (grid[i][j] == 'W') preCnt = 0;
			else if (grid[i][j] == 'E') ++preCnt;

			cnt[i][j] += preCnt;
		}
		preCnt = grid[i][n-1] == 'E' ? 1 : 0;
		for (int j = n - 2 ; j >= 0 ; --j) {
			cnt[i][j] += preCnt;
			if (grid[i][j] == 'W') preCnt = 0;
			else if (grid[i][j] == 'E') ++preCnt;
		}
	}

	for (int j = 0 ; j < n ; ++j) {
		int preCnt = 0;
		for (int i = 0 ; i < m ; ++i) {
			if (grid[i][j] == 'W') preCnt = 0;
			else if (grid[i][j] == 'E') ++preCnt;
			cnt[i][j] += preCnt;
		}
		preCnt = grid[m-1][j] == 'E' ? 1 : 0;
		for (int i = m - 2 ; i >= 0 ; --i) {
			cnt[i][j] += preCnt;
			if (grid[i][j] == 'W') preCnt = 0;
			else if (grid[i][j] == 'E') ++preCnt;
		}
	}

	int result = 0;
	for (int i = 0 ; i < m ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			if (grid[i][j] != '0') continue;
			result = max(result, cnt[i][j]);
		}
	}
	return result;
}

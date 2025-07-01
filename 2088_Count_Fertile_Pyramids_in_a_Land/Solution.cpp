#include <Solution.h>

int getCnt(vector<vector<int>>& grid) {
	int m = grid.size();
	int n = grid[0].size();
	int result = 0;
	vector<int> dp(n, 0);
	for (int i = 0 ; i < m ; ++i) {
		int cnt = 0;
		vector<int> next = grid[i];
		for (int j = 0 ; j < n ; ++j) {
			if (grid[i][j] == 0) {
				cnt = 0;
				continue;
			}
			++cnt;
			for (int sz = 3 ; sz <= cnt ; sz += 2) {
				int center = j - (sz / 2);
				int v = dp[center] == 0 ? 0 : min(dp[center] + 2, sz);
				if (v > 1 && v > next[center]) {
					next[center] = v;
					++result;
				}
			}

		}
		dp = move(next);
	}
	return result;
}

int Solution::countPyramids(vector<vector<int>>& grid) {
	int result = 0;
	int v = getCnt(grid);
	result += v;
	reverse(grid.begin(), grid.end());
	v = getCnt(grid);
	result += v;
	return result;
}

#include <Solution.h>
#include <iostream>

bool Solution::hasValidPath(vector<vector<char>>& grid) {
	int m = grid.size();
	int n = grid[0].size();

	if (grid[0][0] == ')' && (m + n - 1) & 1) return false;
	int limit = (m + n - 1) / 2;
	vector<vector<vector<bool>>> dp(m, vector<vector<bool>>(n, vector<bool>(limit+1, false)));

	dp[0][0][1] = true;
	for (int i = 0 ; i < m ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			if (i == 0 && j == 0) continue;
			int offset = grid[i][j] == '(' ? 1 : -1;
			if (j > 0) {
				for (int k = 0 ; k <= limit ; ++k) {
					if (dp[i][j-1][k]) {
						int val = k + offset;
						if (val >= 0 && val <= limit) dp[i][j][val] = true;
					}
				}
			}
			if (i > 0) {
				for (int k = 0 ; k <= limit ; ++k) {
					if (dp[i-1][j][k]) {
						int val = k + offset;
						if (val >= 0 && val <= limit) dp[i][j][val] = true;
					}
				}
			}
		}
	}
	return dp[m-1][n-1][0];
}

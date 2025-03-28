#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
using std::min;

int Solution::cherryPickup2(vector<vector<int>> &grid) {
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<int>> dp(n, vector<int>(n, 0));
	vector<vector<int>> next(n, vector<int>(n, 0));

	dp[0][n - 1] = grid[0][0] + grid[0][n - 1];
	for (int i = 1; i < m; ++i) {
		for (int c1 = 0; c1 < min(n, i + 1); ++c1) {
			for (int c2 = max(0, n - i - 1); c2 < n; ++c2) {
				int prev_max = 0;
				for (int j = max(0, c1 - 1); j < min(n, c1 + 2); ++j) {
					for (int k = max(0, c2 - 1); k < min(n, c2 + 2); ++k) {
						prev_max = max(prev_max, dp[j][k]);
					}
				}
				next[c1][c2] = prev_max + ((c1 == c2) ? grid[i][c1] : grid[i][c1] + grid[i][c2]);
			}
		}
		swap(dp, next);
	}
	int result = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			result = max(result, dp[i][j]);
		}
	}
	return result;
}

#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
using std::min;
// prev_max is combination of two robot moving
// prev_max = max{
//	dp[r - 1][c1 - 1][c2 - 1],
//	dp[r - 1][c1 - 1][c2],
//	dp[r - 1][c1 - 1][c2 + 1],
//	dp[r - 1][c1][c2 - 1],
//	dp[r - 1][c1][c2],
//	dp[r - 1][c1][c2 + 1],
//	dp[r - 1][c1 + 1][c2 - 1],
//	dp[r - 1][c1 + 1][c2],
//	dp[r - 1][c1 + 1][c2 + 1]
// };
// dp[r][c1][c2] = prev_max + grid[r][c1] + grid[r][c2];
// result = max(dp[m-1][c1][c2]);

int Solution::cherryPickup(vector<vector<int>> &grid) {
	int m = grid.size(), n = grid[0].size();
	vector<vector<int>> dp(n, vector<int>(n, 0));
	vector<vector<int>> next(n, vector<int>(n, 0));

	dp[0][n - 1] = 0 == n - 1 ? grid[0][0] : grid[0][0] + grid[0][n - 1];
	for (int r = 1; r < m; ++r) {
		for (int c1 = 0; c1 < min(n, r + 1); ++c1) {
			for (int c2 = max(0, (n - 1) - r); c2 < n; ++c2) {
				int prev_max = 0;
				for (int offset1 = max(0, c1 - 1); offset1 <= min(n - 1, c1 + 1); ++offset1) {
					for (int offset2 = max(0, c2 - 1); offset2 <= min(n - 1, c2 + 1); ++offset2) {
						prev_max = max(prev_max, dp[offset1][offset2]);
					}
				}
				next[c1][c2] = prev_max + ((c1 == c2) ? grid[r][c1] : grid[r][c1] + grid[r][c2]);
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

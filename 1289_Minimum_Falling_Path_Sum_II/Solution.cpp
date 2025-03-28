#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::cout;
using std::endl;
using std::min;
using std::pair;

int Solution::minFallingPathSum(vector<vector<int>> &grid) {
	int n = grid.size();
	int result = INT_MAX;
	vector<vector<int>> dp = grid;

	for (int i = 1; i < n; ++i) {
		int m1 = INT_MAX, m2 = INT_MAX;
		for (const auto v : dp[i - 1]) {
			if (v <= m1) {
				m2 = m1;
				m1 = v;
			} else if (v <= m2) {
				m2 = v;
			}
		}
		for (int j = 0; j < n; ++j) {
			dp[i][j] = dp[i][j] + (dp[i - 1][j] > m1 ? m1 : m2);
			if (i == n - 1) {
				result = min(result, dp[i][j]);
			}
		}
	}
	return n == 1 ? grid[0][0] : result;
}

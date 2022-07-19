#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;

int Solution::minCostII(vector<vector<int>>& costs) {
	int n = costs.size();
	int cn = costs[0].size();
	vector<vector<int>> dp(n, vector<int>(cn, INT_MAX));

	dp[0] = costs[0];

	for (int i = 1 ; i < n ; ++i) {
		for (int c = 0 ; c < cn ; ++c) {
			for (int lc = 0 ; lc < cn ; ++lc) {
				if (c != lc) {
					dp[i][c] = min(dp[i][c], dp[i-1][lc] + costs[i][c]);
				}
			}
		}
	}
	int result = INT_MAX;
	for (int i = 0 ; i < cn ; ++i) {
		result = min(result, dp[n-1][i]);
	}
	return result;
}

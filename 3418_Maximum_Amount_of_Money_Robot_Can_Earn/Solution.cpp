#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::cout;
using std::endl;
using std::max;

int Solution::maximumAmount(vector<vector<int>> &coins) {
	int m = coins.size();
	int n = coins[0].size();
	vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));

	dp[0][0][0] = coins[0][0];
	dp[0][0][1] = max(coins[0][0], 0);
	dp[0][0][2] = max(coins[0][0], 0);

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			int v = max(coins[i][j], 0);
			if (i > 0) {
				dp[i][j][0] = max(dp[i - 1][j][0] + coins[i][j], dp[i][j][0]);
				dp[i][j][1] = max({dp[i - 1][j][0] + v, dp[i - 1][j][1] + coins[i][j], dp[i][j][1]});
				dp[i][j][2] = max({dp[i - 1][j][1] + v, dp[i - 1][j][2] + coins[i][j], dp[i][j][2]});
			}
			if (j > 0) {
				dp[i][j][0] = max(dp[i][j - 1][0] + coins[i][j], dp[i][j][0]);
				dp[i][j][1] = max({dp[i][j - 1][0] + v, dp[i][j - 1][1] + coins[i][j], dp[i][j][1]});
				dp[i][j][2] = max({dp[i][j - 1][1] + v, dp[i][j - 1][2] + coins[i][j], dp[i][j][2]});
			}
		}
	}
	int result = INT_MIN;
	for (int i = 0; i < 3; ++i)
		result = max(result, dp.back().back()[i]);
	return result;
}

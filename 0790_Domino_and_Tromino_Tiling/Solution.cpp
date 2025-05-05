#include <Solution.h>

int Solution::numTilings(int n) {
	vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));

	long long mod = 1e9 + 7;

	dp[0][0] = 1;
	for (int i = 1 ; i <= n ; ++i) {
		// full case
		dp[i][0] = dp[i-1][0] + dp[i-1][1];
		if (i > 1) {
			// horization
			dp[i][0] += dp[i-2][0];
		}
		dp[i][0] %= mod;

		// lack case
		dp[i][1] = dp[i-1][1];
		if (i > 1) {
			dp[i][1] += 2 * dp[i-2][0];
		}
		dp[i][1] %= mod;
	}
	return dp.back()[0];
}

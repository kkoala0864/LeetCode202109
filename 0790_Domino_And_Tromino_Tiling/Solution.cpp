#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

int Solution::numTilings(int n) {
	int mod = 1e9 + 7;
	vector<vector<long>> dp(n + 1, vector<long>(3, 0));

	dp[0][0] = dp[1][0] = 1;

	for (int i = 2 ; i <= n ; ++i) {
		dp[i][0] = (dp[i-1][0] + dp[i-2][0] + dp[i-1][1] + dp[i-1][2]) % mod;
		dp[i][1] = (dp[i-1][1] + dp[i-2][0]) % mod;
		dp[i][2] = (dp[i-1][2] + dp[i-2][0]) % mod;
	}
	return dp[n][0];
}

#include <Solution.h>
#include <iostream>
#include <vector>

using std::pair;
using std::vector;

int Solution::numTilings(int n) {
	vector<pair<long, long>> dp(n + 1, pair<long, long>(0, 0));
	int mod = 1e9 + 7;
	dp[0].first = 1;

	for (int i = 1; i <= n; ++i) {
		// two pieces
		dp[i].first += dp[i - 1].first;
		dp[i].second += dp[i - 1].second;
		if (i > 1) {
			dp[i].first += dp[i - 2].first;
		}
		dp[i].first %= mod;
		dp[i].second %= mod;

		// three pieces
		dp[i].first += dp[i - 1].second;
		if (i > 1) {
			dp[i].second += (2 * dp[i - 2].first);
		}
		dp[i].first %= mod;
		dp[i].second %= mod;
	}
	return dp.back().first;
}

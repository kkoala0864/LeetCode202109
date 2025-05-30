#include <Solution.h>

int Solution::coinChange(vector<int> &coins, int amount) {
	vector<int> dp(amount + 1, INT_MAX);

	dp[0] = 0;
	for (int i = 1 ; i <= amount ; ++i) {
		for (const auto& c : coins) {
			if (c > i || dp[i-c] == INT_MAX) continue;
			dp[i] = min(dp[i], dp[i-c] + 1);
		}
	}
	return dp.back() == INT_MAX ? -1 : dp.back();
}

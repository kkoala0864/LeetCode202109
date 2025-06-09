#include <Solution.h>

int Solution::change(int amount, vector<int> &coins) {
	vector<int> dp(amount + 1, 0);
	dp[0] = 1;
	for (const auto& c : coins) {
		for (int i = 1 ; i <= amount ; ++i) {
			if (i < c) continue;
			dp[i] += dp[i-c];
		}
	}
	return dp[amount];
}

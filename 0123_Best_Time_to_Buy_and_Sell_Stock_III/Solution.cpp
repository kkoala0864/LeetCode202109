#include <Solution.h>

int Solution::maxProfit(vector<int> &prices) {
	int size = prices.size();

	vector<int> dp(4, INT_MIN), next(4, INT_MIN);
	for (int i = 0 ; i < size ; ++i) {
		next[0] = max(dp[0], -prices[i]);
		next[1] = max(dp[1], dp[0] + prices[i]);
		if (i >= 2) {
			next[2] = max(dp[2], dp[1] - prices[i]);
			next[3] = max(dp[3], dp[2] + prices[i]);
		}
		dp = next;
	}
	return max({0, dp[1], dp[3]});

}

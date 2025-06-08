#include <Solution.h>

int Solution::maxProfit(vector<int> &prices) {
	int size = prices.size();
	vector<int> dp(2, 0), next(2, 0);

	dp[0] = 0;
	dp[1] = -prices[0];

	for (int i = 1 ; i < size ; ++i) {
		next[0] = max(dp[0], dp[1] + prices[i]);
		next[1] = max(dp[1], dp[0] - prices[i]);
		dp = next;
	}
	return dp[0];
}

#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::sort;
using std::min;

int Solution::coinChange4(vector<int>& coins, int amount) {
	vector<int> dp(amount + 1, INT_MAX);
	dp[0] = 0;

	for (int i = 1 ; i <= amount ; ++i) {
		for (const auto& coin : coins) {
			if ((i - coin) >= 0 && dp[i-coin] != INT_MAX) {
				dp[i] = min(dp[i], dp[i-coin] + 1);
			}
		}
	}
	return dp[amount] == INT_MAX ? -1 : dp[amount];
}

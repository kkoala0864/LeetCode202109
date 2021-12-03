#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::sort;
using std::min;

int Solution::coinChange2(vector<int>& coins, int amount) {
	vector<int> dp(amount+1, INT_MAX);
	dp[0] = 0;

	for (int i = 1 ; i <= amount ; ++i) {
		for (const auto& iter : coins) {
			if (iter <= i && dp[i-iter] != INT_MAX) {
				dp[i] = min(dp[i-iter] + 1, dp[i]);
			}
		}
	}
	return dp[amount] == INT_MAX ? -1 : dp[amount];
}

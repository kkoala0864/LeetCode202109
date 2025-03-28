#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::min;
using std::sort;

int Solution::coinChange3(vector<int> &coins, int amount) {
	vector<int> dp(amount + 1, INT_MAX);
	dp[0] = 0;
	for (int i = 1; i <= amount; ++i) {
		for (const auto &coin : coins) {
			if (coin > i)
				continue;
			if (dp[i - coin] == INT_MAX)
				continue;
			dp[i] = min(1 + dp[i - coin], dp[i]);
		}
	}
	return dp[amount] == INT_MAX ? -1 : dp[amount];
}

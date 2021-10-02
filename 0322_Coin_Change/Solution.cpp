#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::sort;
using std::min;

/*
int combination(const vector<int>& coins, int idx, int rest) {
	if (rest == 0) return 0;
	if ((idx < 0) && (rest > 0)) return -1;

	int localMin = INT_MAX;
	int div = rest / coins[idx];
	for (int i = div ; i >= 0 ; --i) {
		int nextCnt = combination(coins, idx - 1, rest - (coins[idx] * i));
		if (nextCnt >= 0) {
			localMin = min(localMin, nextCnt + i);
		}
	}
	return localMin == INT_MAX ? -1 : localMin;
}

int Solution::coinChange(vector<int>& coins, int amount) {
	sort(coins.begin(), coins.end());
	return combination(coins, coins.size() - 1, amount);
}
*/

int Solution::coinChange(vector<int>& coins, int amount) {
	vector<int> dp(amount + 1, INT_MAX);
	dp[0] = 0;

	for (const auto& coin : coins) {
		for (int i = coin ; i <= amount ; ++i) {
			if (dp[i-coin] != INT_MAX) {
				dp[i] = min(dp[i], dp[i-coin] + 1);
			}
		}
	}
	return dp[amount] == INT_MAX ? -1 : dp[amount];
}

#include <Solution.h>
#include <iostream>
#include <numeric>

// target - (sum - target) = |2 * target - sum| = sum - (2 * target) = min(sum - 2 * target) = max(target);
int Solution::lastStoneWeightII(vector<int>& stones) {
	int sum = accumulate(stones.begin(), stones.end(), 0);
	int target = sum >> 1;

	vector<bool> dp(target + 1, false);

	dp[0] = true;

	for (const auto& s : stones) {
		for (int i = target ; i >= s ; --i) {
			dp[i] = dp[i] || dp[i-s];
		}
	}

	for (int i = target ; i >= 0 ; --i) {
		if (dp[i]) return sum - 2 * i;
	}
	return -1;
}

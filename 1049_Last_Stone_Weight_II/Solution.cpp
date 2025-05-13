#include <Solution.h>

// this problem can be treated as find two subset which most closed to (sum / 2)
int Solution::lastStoneWeightII(vector<int>& stones) {
	int sum = accumulate(stones.begin(), stones.end(), 0);
	int target = sum >> 1;

	vector<bool> dp(target + 1, false), next;
	dp[0] = true;
	next = dp;

	int maxValue = 0;
	for (const auto& v : stones) {
		for (int i = v ; i <= target ; ++i) {
			next[i] = dp[i] || dp[i-v];
			if (next[i]) maxValue = max(maxValue, i);
		}
		dp = next;
	}

	return sum - (2 * maxValue);
}

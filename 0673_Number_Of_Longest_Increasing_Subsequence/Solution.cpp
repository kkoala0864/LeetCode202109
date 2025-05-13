#include <Solution.h>

int Solution::findNumberOfLIS(vector<int> &nums) {
	vector<pair<int, int>> dp;

	int maxLen = 0;

	for (int i = 0 ; i < nums.size() ; ++i) {
		int curMax = 0;
		dp.emplace_back(pair<int, int>(1, 1));
		for (int j = 0 ; j < i ; ++j) {
			if (nums[i] <= nums[j]) continue;
			int lastLen = dp[j].first + 1;
			if (lastLen > dp[i].first) {
				dp[i].first = dp[j].first + 1;
				dp[i].second = dp[j].second;
			} else if (lastLen == dp[i].first) {
				dp[i].second += dp[j].second;
			}
		}
		maxLen = max(maxLen, dp[i].first);
	}
	int result = 0;
	for (const auto& p : dp) {
		if (p.first != maxLen) continue;
		result += p.second;
	}
	return result;
}

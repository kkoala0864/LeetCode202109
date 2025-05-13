#include <Solution.h>

bool Solution::canPartition(vector<int> &nums) {
	int sum = accumulate(nums.begin(), nums.end(), 0);
	if (sum & 1) return false;

	sum >>= 1;

	vector<bool> dp(sum + 1, false), next;
	dp[0] = true;
	next = dp;
	for (const auto& v : nums) {
		for (int i = v ; i <= sum ; ++i) {
			if (dp[i - v]) {
				next[i] = true;
			}
		}
		dp = next;
		if (dp.back()) return true;
	}
	return dp[sum];
}

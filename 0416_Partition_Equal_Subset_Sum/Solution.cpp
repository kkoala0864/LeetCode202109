#include <Solution.h>

bool Solution::canPartition(vector<int> &nums) {
	int target = 0;
	target = accumulate(nums.begin(), nums.end(), target);
	if (target & 1) return false;

	target >>= 1;

	vector<bool> dp(target + 1, false);
	dp[0] = true;
	for (const auto& v : nums) {
		for (int i = target ; i >= v ; --i) {
			dp[i] = dp[i] | dp[i-v];
		}
	}
	return dp[target];
}

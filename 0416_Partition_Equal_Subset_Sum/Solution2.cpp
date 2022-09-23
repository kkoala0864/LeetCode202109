#include <Solution.h>
#include <iostream>

bool Solution::canPartition2(vector<int>& nums) {
	int sum = 0;
	for (const auto& v : nums) sum += v;

	if (sum & 1) return false;
	sum >>= 1;

	vector<int> dp(sum + 1, false);
	dp[0] = true;

	vector<int> next = dp;
	for (const auto& v : nums) {
		for (int j = v ; j <= sum ; ++j) {
			if (dp[j-v]) {
				next[j] = true;
			}
		}
		dp = next;
	}
	return dp[sum];
}

#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

bool Solution::canPartition(vector<int>& nums) {
	int sum = 0;
	for (const auto& v : nums) sum += v;

	if (sum & 1) return false;
	sum >>= 1;

	vector<bool> dp(sum + 1, false);
	dp[0] = true;
	vector<bool> next = dp;
	for (int i = 0 ; i < nums.size() ; ++i) {
		for (int j = nums[i] ; j <= sum ; ++j) {
			if (dp[j - nums[i]]) next[j] = true;
		}
		dp = next;
	}
	return dp[sum];
}

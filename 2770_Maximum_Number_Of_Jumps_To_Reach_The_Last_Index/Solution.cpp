#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int Solution::maximumJumps(vector<int>& nums, int target) {
	vector<int> dp(nums.size(), -1);
	dp[0] = 0;
	for (int i = 1 ; i < nums.size() ; ++i) {
		for (int j = 0 ; j < i ; ++j) {
			int diff = nums[i] - nums[j];
			if (diff < -target || diff > target || dp[j] == -1) continue;
			dp[i] = max(dp[i], dp[j]);
		}
		dp[i] += dp[i] == -1 ? 0 : 1;
	}
	return dp.back();
}

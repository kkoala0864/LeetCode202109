#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::min;

int Solution::jump2(vector<int> &nums) {
	vector<int> dp(nums.size(), INT_MAX);
	dp[0] = 0;
	for (int i = 0; i < nums.size(); ++i) {
		for (int j = 1; j <= nums[i]; ++j) {
			if (i + j >= nums.size())
				break;
			if ((i + j) == nums.size() - 1)
				return dp[i] + 1;
			dp[i + j] = min(dp[i + j], dp[i] + 1);
		}
	}
	return dp.back();
}

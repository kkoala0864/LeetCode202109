#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int Solution::combinationSum4(vector<int> &nums, int target) {
	vector<unsigned long long> dp(target + 1, 0);
	dp[0] = 1;

	for (int i = 1; i <= target; ++i) {
		for (const auto &v : nums) {
			if (v <= i)
				dp[i] += dp[i - v];
		}
	}
	return dp[target];
}

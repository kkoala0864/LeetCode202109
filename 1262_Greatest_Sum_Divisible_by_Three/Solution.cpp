#include <Solution.h>

int Solution::maxSumDivThree(vector<int>& nums) {
	vector<int> dp(3, INT_MIN), last(3, INT_MIN);

	dp[0] = last[0] = 0;

	for (int i = 0 ; i < nums.size() ; ++i) {
		int curMod = nums[i] % 3;
		for (int j = 0 ; j < 3 ; ++j) {
			if (last[j] == INT_MIN) continue;
			int n = (curMod + j) % 3;
			dp[n] = max(dp[n], last[j] + nums[i]);
		}
		last = dp;
	}
	return dp[0];
}

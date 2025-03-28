#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int Solution::totalSteps(vector<int> &nums) {
	vector<int> dp(nums.size(), 0), st;
	int result = 0;

	for (int i = nums.size() - 1; i >= 0; --i) {
		while (!st.empty() && nums[st.back()] < nums[i]) {
			dp[i] = max(dp[i] + 1, dp[st.back()]);
			st.pop_back();
		}
		result = max(dp[i], result);
		st.emplace_back(i);
	}
	return result;
}

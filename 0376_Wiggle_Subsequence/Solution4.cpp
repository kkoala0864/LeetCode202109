#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int Solution::wiggleMaxLength4(vector<int> &nums) {
	vector<vector<int>> dp(nums.size(), vector<int>(2, 0));

	dp[0][0] = 1;
	dp[0][1] = 1;

	int result = 1;
	for (int i = 1; i < nums.size(); ++i) {
		for (int j = i - 1; j >= 0 && (dp[i][0] == 0 || dp[i][1] == 0); --j) {
			if (nums[i] - nums[j] > 0) {
				dp[i][0] = max(dp[j][1] + 1, dp[i][0]);
				result = max(dp[i][0], result);
			}
			if (nums[i] - nums[j] < 0) {
				dp[i][1] = max(dp[j][0] + 1, dp[i][1]);
				result = max(dp[i][1], result);
			}
		}
	}
	return result;
}

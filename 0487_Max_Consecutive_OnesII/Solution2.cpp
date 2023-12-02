#include "Solution.h"
#include <iostream>
#include <algorithm>

using std::max;

int Solution::findMaxConsecutiveOnes2(vector<int>& nums) {
	int size = nums.size();
	vector<vector<int>> dp(size + 1, vector<int>(2, 0));

	int result = 0;
	for (int i = 0 ; i < nums.size() ; ++i) {
		if (nums[i] == 1) {
			dp[i+1][0] = dp[i][0] + 1;
			dp[i+1][1] = dp[i][1] + 1;
		} else {
			dp[i+1][0] = 0;
			dp[i+1][1] = dp[i][0] + 1;
		}
		result = max({result, dp[i+1][0], dp[i+1][1]});
	}
	return result;
}

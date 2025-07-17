#include <Solution.h>

int Solution::maximumLength(vector<int>& nums, int k) {
	int size = nums.size();
	vector<vector<int>> dp(size, vector<int>(k, 1));
	int result = 0;
	for (int i = 0 ; i < nums.size() ; ++i) {
		for (int j = 0 ; j < i ; ++j) {
			int mod = (nums[i] + nums[j]) % k;
			dp[i][mod] = max(dp[i][mod], dp[j][mod] + 1);
			result = max(result, dp[i][mod]);
		}
	}
	return result;
}

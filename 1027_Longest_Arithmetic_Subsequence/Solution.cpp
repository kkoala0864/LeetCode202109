#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using std::unordered_map;
using std::max;

int Solution::longestArithSeqLength(vector<int>& nums) {
	if (nums.empty()) return 0;
	vector<unordered_map<int, int>> dp(nums.size(), unordered_map<int, int>());

	int result = 0;
	for (int i = 1 ; i < nums.size() ; ++i) {
		for (int j = i - 1 ; j >= 0 ; --j) {
			int diff = nums[i] - nums[j];
			dp[i][diff] = max(dp[j][diff] + 1, dp[i][diff]);
			result = max(result, dp[i][diff]);
		}
	}
	return result + 1;
}

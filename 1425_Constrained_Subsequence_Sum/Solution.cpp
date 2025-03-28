#include <Solution.h>
#include <iostream>
#include <map>
#include <algorithm>

using std::greater;
using std::map;
using std::max;

int Solution::constrainedSubsetSum(vector<int> &nums, int k) {
	map<int, int, greater<int>> m;
	vector<int> dp(nums.size(), INT_MIN);
	int result = nums[0];
	dp[0] = nums[0];
	++m[dp[0]];

	for (int i = 1; i < nums.size(); ++i) {
		if (i - k - 1 >= 0) {
			--m[dp[i - k - 1]];
			if (m[dp[i - k - 1]] == 0)
				m.erase(dp[i - k - 1]);
		}

		dp[i] = max(dp[i], m.begin()->first + nums[i]);
		dp[i] = max(dp[i], nums[i]);
		++m[dp[i]];
		result = max(result, dp[i]);
	}
	return result;
}

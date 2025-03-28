#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::max;
using std::pair;

int Solution::longestSubsequence(vector<int> &nums) {
	vector<vector<int>> dp(301, vector<int>(301, 0));
	int result = 1;

	for (int i = 0; i < nums.size(); ++i) {
		int cur = nums[i];
		for (int n = 1; n <= 300; ++n) {
			int diff = abs(n - cur);
			dp[cur][diff] = max(dp[cur][diff], dp[n][diff] + 1);
		}

		for (int j = 299; j >= 0; --j) {
			dp[cur][j] = max(dp[cur][j], dp[cur][j + 1]);
		}
	}

	for (int i = 0; i <= 300; ++i) {
		for (int j = 0; j <= 300; ++j) {
			result = max(result, dp[i][j]);
		}
	}
	return result;
}

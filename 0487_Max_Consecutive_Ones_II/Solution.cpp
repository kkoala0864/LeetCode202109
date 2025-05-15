#include <Solution.h>

int Solution::findMaxConsecutiveOnes(vector<int> &nums) {
	vector<int> dp(2, 0);

	int result = 0;

	for (const auto& v : nums) {
		if (v == 1) {
			++dp[0];
			++dp[1];
		} else {
			dp[1] = dp[0] + 1;
			dp[0] = 0;
		}
		result = max({result, dp[0], dp[1]});
	}
	return result;
}

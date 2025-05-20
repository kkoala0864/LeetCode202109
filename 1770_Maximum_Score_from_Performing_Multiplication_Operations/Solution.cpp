#include <Solution.h>

// dp[i][j] : max sum of i element which take left j and right (i - j)
int Solution::maximumScore(vector<int>& nums, vector<int>& multipliers) {
	int n = nums.size();
	int m = multipliers.size();

	vector<vector<int>> dp(m + 1, vector<int>(m + 1, INT_MIN));
	dp[0][0] = 0;

	for (int i = 1 ; i <= m ; ++i) {
		for (int j = 0 ; j <= i ; ++j) {
			if (j > 0) {
				dp[i][j] = max(dp[i][j], dp[i-1][j-1] + (multipliers[i - 1] * nums[j - 1]));
			}
			if (j < i) {
				dp[i][j] = max(dp[i][j], dp[i-1][j] + (multipliers[i - 1] * nums[n - (i - j)]));
			}
		}
	}

	int result = INT_MIN;
	for (int i = 0 ; i <= m ; ++i) {
		result = max(result, dp[m][i]);
	}
	return result;
}

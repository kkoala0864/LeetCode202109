#include <Solution.h>
#include <iostream>
#include <vector>
#include <algorithm>

using std::max;
using std::vector;

int Solution::longestCommonSubsequence2(string text1, string text2) {
	int m = text1.size();
	int n = text2.size();
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			dp[i][j] = text1[i - 1] == text2[j - 1] ? dp[i - 1][j - 1] + 1 : max(dp[i][j - 1], dp[i - 1][j]);
		}
	}
	return dp[m][n];
}

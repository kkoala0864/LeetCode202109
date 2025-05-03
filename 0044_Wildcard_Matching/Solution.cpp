#include <Solution.h>
#include <iostream>
#include <unordered_set>
#include <vector>

bool Solution::isMatch(string s, string p) {
	int m = s.size();
	int n = p.size();

	vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

	dp[0][0] = true;
	for (int i = 1 ; i <= n ; ++i) {
		if (p[i - 1] != '*') break;
		dp[0][i] = true;
	}

	for (int i = 0 ; i < m ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			if (p[j] == '?') {
				dp[i+1][j+1] = dp[i][j];
			} else if (p[j] == '*') {
				dp[i+1][j+1] = dp[i][j+1] || dp[i+1][j];
			} else {
				dp[i+1][j+1] = dp[i][j] && (s[i] == p[j]);
			}
		}
	}
	return dp.back().back();
}

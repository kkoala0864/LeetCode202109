#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

bool Solution::isMatch(string s, string p) {
	int m = s.size();
	int n = p.size();

	vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

	s = "#" + s;
	p = "#" + p;

	// dp[0][j] -> 1 ~ n
	dp[0][0] = true;
	for (int i = 2; i < p.size(); i += 2) {
		dp[0][i] = p[i] == '*' && dp[0][i - 2];
	}

	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (isalpha(p[j])) {
				dp[i][j] = (s[i] == p[j] || p[j] == '.') && dp[i - 1][j - 1];
			} else if (p[j] == '*') {
				dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && (s[i] == p[j - 1] || p[j - 1] == '.'));
			} else if (p[j] == '.') {
				dp[i][j] = dp[i - 1][j - 1];
			}
		}
	}
	return dp[m][n];
}

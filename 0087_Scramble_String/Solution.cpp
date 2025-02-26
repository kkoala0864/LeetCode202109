#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

bool Solution::isScramble(string s1, string s2) {
	int n = s1.size();
	vector<vector<vector<bool>>> dp(n + 1, vector<vector<bool>>(n, vector<bool>(n, false)));

	for (int i = 0 ; i < n ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			dp[1][i][j] = s1[i] == s2[j];
		}
	}

	for (int s = 2 ; s <= n ; ++s) {
		for (int i1 = 0 ; (i1 + s) <= n ; ++i1) {
			for (int i2 = 0 ; (i2 + s) <= n ; ++i2) {

				for (int k = 1 ; k < s ; ++k) {
					dp[s][i1][i2] = dp[s][i1][i2] || dp[k][i1][i2] && dp[s-k][i1+k][i2+k];
					dp[s][i1][i2] = dp[s][i1][i2] || dp[k][i1][i2+(s-k)] && dp[s-k][i1+k][i2];
				}
			}
		}
	}
	return dp[n][0][0];
}

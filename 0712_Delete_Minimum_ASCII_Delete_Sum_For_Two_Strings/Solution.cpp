#include <Solution.h>
#include <iostream>
#include <vector>
#include <algorithm>

using std::min;
using std::vector;

int Solution::minimumDeleteSum(string s1, string s2) {
	int sz1 = s1.size();
	int sz2 = s2.size();

	vector<vector<int>> dp(sz1 + 1, vector<int>(sz2 + 1, INT_MAX));

	dp[0][0] = 0;
	for (int i = 0; i <= sz1; ++i) {
		for (int j = 0; j <= sz2; ++j) {
			if (i == 0 && j == 0)
				continue;
			if (i == 0) {
				dp[i][j] = dp[i][j - 1] + s2[j - 1];
			} else if (j == 0) {
				dp[i][j] = dp[i - 1][j] + s1[i - 1];
			} else {
				if (s1[i - 1] == s2[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1];
				} else {
					dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
				}
			}
		}
	}
	return dp[sz1][sz2];
}

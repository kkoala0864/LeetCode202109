#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <vector>

using std::max;
using std::vector;

// i and j means siz
int Solution::minDistance(string word1, string word2) {
	int m = word1.size(), n = word2.size();
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
	for (int i = 0; i <= m; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (i == 0 || j == 0)
				continue;
			else
				dp[i][j] = (word1[i - 1] == word2[j - 1]) ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	return m + n - (2 * dp[m][n]);
}

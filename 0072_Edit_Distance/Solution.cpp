#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <vector>

using std::min;
using std::vector;

int Solution::minDistance(string word1, string word2) {
	int s1 = word1.size();
	int s2 = word2.size();
	vector<vector<int>> dp(s1 + 1, vector<int>(s2 + 1, 0));

	// i means size from word1 index 0;
	// j means size from word2 index 0;
	// if i == 0 just insert/remove j size character
	// if j == 0 just insert/remove i size character
	for (int i = 0; i <= s1; ++i)
		dp[i][0] = i;
	for (int j = 0; j <= s2; ++j)
		dp[0][j] = j;

	// if last character equal then no need to change ( cost 0 )
	// if not equal need to replace ( cost 1 )
	// there are three posibility : replace(dp[i-1][j-1] + c), insert(dp[i-1][j]+1), remove(dp[i][j-1]+1)
	for (int i = 1; i <= s1; ++i) {
		for (int j = 1; j <= s2; ++j) {
			int c = word1[i - 1] == word2[j - 1] ? 0 : 1;

			dp[i][j] = min({dp[i - 1][j - 1] + c,
			                dp[i][j - 1] + 1,
			                dp[i - 1][j] + 1});
		}
	}
	return dp[s1][s2];
}

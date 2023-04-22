#include <Solution.h>
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::min;

int Solution::minInsertions(string s) {
	vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));

	for (int j = 1 ; j < s.size() ; ++j) {
		for (int i = 0 ; (i + j) < s.size() ; ++i) {
			if (s[i] == s[i + j]) {
				dp[i][i + j] = j == 1 ? 0 : dp[i+1][i+j-1];
			} else {
				dp[i][i + j] = j == 1 ? 1 : min(dp[i][i+j-1], dp[i+1][i+j]) + 1;
			}
		}
	}
	return dp[0][s.size()-1];
}

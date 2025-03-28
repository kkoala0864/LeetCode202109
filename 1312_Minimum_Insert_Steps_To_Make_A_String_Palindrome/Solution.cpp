#include <Solution.h>
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::min;
using std::vector;

int Solution::minInsertions(string s) {
	int size = s.size();
	vector<vector<int>> dp(size, vector<int>(size, INT_MAX));

	for (int j = 0; j < size; ++j) {
		for (int i = j; i >= 0; --i) {
			if (i == j) {
				dp[i][j] = 0;
			} else {
				if (s[i] == s[j]) {
					dp[i][j] = (j - i + 1) < 3 ? 0 : dp[i + 1][j - 1];
				} else {
					dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
				}
			}
		}
	}
	return dp[0][size - 1];
}

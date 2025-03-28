#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::max;
using std::vector;

int Solution::longestPalindromeSubseq(string s) {
	int size = s.size();

	vector<vector<int>> dp(size, vector<int>(size, 1));

	for (int i = 0; i < size; ++i) {
		for (int j = i - 1; j >= 0; --j) {
			if (s[i] != s[j]) {
				dp[j][i] = max(dp[j + 1][i], dp[j][i - 1]);
			} else {
				if (i - j < 2) {
					dp[j][i] = i - j + 1;
				} else {
					dp[j][i] = dp[j + 1][i - 1] + 2;
				}
			}
		}
	}
	return dp[0][size - 1];
}

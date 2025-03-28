#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::max;
using std::vector;

bool Solution::isValidPalindrome(string s, int k) {
	int size = s.size();
	int mLen = 1;
	vector<vector<int>> dp(size, vector<int>(size, 1));

	for (int i = 0; i < size; ++i) {
		int maxLen = 1;
		for (int j = i - 1; j >= 0; --j) {
			if (i - j == 1) {
				maxLen = max(maxLen, s[j] == s[i] ? 2 : 1);
			} else {
				maxLen = max(maxLen, s[j] == s[i] ? 2 + dp[j + 1][i - 1] : max(dp[j + 1][i], dp[j][i - 1]));
			}
			dp[j][i] = maxLen;
			mLen = max(mLen, maxLen);
		}
	}
	return (s.size() - mLen) <= k;
}

#include <Solution.h>
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::max;

string Solution::longestPalindrome4(string s) {
	vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
	int l = 0, r = 0;
	int result = 0;

	for (int i = 0 ; i < s.size() ; ++i) {
		for (int j = 0 ; j <= i ; ++j) {
			if (s[i] == s[j]) {
				if (i == j) dp[i][j] = 1;
				else if ((i - j) == 1) dp[i][j] = 2;
				else if ((i - 1) >= (j + 1)) dp[i][j] = dp[i-1][j+1] > 0 ? (i - j) + 1 : 0;
			}
			if (dp[i][j] > result) {
				l = j;
				r = i;
				result = dp[i][j];
			}
		}
	}
	return s.substr(l, r - l + 1);

}

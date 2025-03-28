#include <Solution.h>
#include <iostream>
#include <vector>
#include <algorithm>

using std::min;
using std::vector;

bool ispalindrome(const string &s, int start, int end) {
	while (start <= end)
		if (s[start++] != s[end--])
			return false;
	return true;
}

int dfs(const string &s, int start, int end, vector<vector<int>> &dp) {
	if (dp[start][end] != -1)
		return dp[start][end];
	int local = s.size();
	if (ispalindrome(s, start, end)) {
		local = 0;
	} else {
		for (int i = start; i < end; ++i) {
			if (dfs(s, start, i, dp) == 0) {
				local = min(dfs(s, i + 1, end, dp) + 1, local);
			}
		}
	}
	return dp[start][end] = local;
}

int Solution::minCut2(string s) {
	vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
	return dfs(s, 0, s.size() - 1, dp);
}

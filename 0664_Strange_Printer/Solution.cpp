#include <Solution.h>

int Solution::strangePrinter(string s) {
	string tmp(1, s[0]);
	for (const auto& c : s) {
		if (c == tmp.back()) continue;
		tmp.push_back(c);
	}
	s = move(tmp);
	int size = s.size();
	vector<vector<int>> dp(size, vector<int>(size, INT_MAX));

	for (int i = 0 ; i < size ; ++i) dp[i][i] = 1;
	for (int sz = 2 ; sz <= size ; ++sz) {
		for (int l = 0 ; (l + sz - 1) < size ; ++l) {
			int r = l + sz - 1;
			dp[l][r] = dp[l][r-1] + 1;
			for (int k = l ; k < r ; ++k) {
				if (s[k] == s[r]) {
					dp[l][r] = min(dp[l][r], dp[l][k] + dp[k+1][r-1]);
				}
			}
		}
	}
	return dp[0][size-1];

}

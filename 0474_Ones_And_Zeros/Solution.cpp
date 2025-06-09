#include <Solution.h>

int Solution::findMaxForm(vector<string> &strs, int m, int n) {
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)), next(m + 1, vector<int>(n + 1, 0));

	vector<pair<int, int>> list;
	for (const auto& s : strs) {
		pair<int, int> cur(0, 0);
		for (const auto& c : s) {
			if (c == '0') ++cur.first;
			else ++cur.second;
		}
		list.emplace_back(cur);
	}

	for (const auto& p : list) {
		for (int i = p.first ; i <= m ; ++i) {
			for (int j = p.second ; j <= n ; ++j) {
				next[i][j] = max(dp[i-p.first][j-p.second] + 1, dp[i][j]);
			}
		}
		dp = next;
	}
	return dp[m][n];
}

#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::max;
using std::pair;

int Solution::findMaxForm(vector<string> &strs, int m, int n) {
	vector<pair<int, int>> list;
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
	auto next = dp;
	for (const auto &s : strs) {
		int cnt0 = 0, cnt1 = 0;
		for (const auto &c : s) {
			if (c == '0')
				++cnt0;
			else
				++cnt1;
		}
		list.emplace_back(pair<int, int>(cnt0, cnt1));
	}
	int result = 0;
	for (const auto &v : list) {
		for (int i = v.first; i <= m; ++i) {
			for (int j = v.second; j <= n; ++j) {
				next[i][j] = max(next[i][j], dp[i - v.first][j - v.second] + 1);
				result = max(result, next[i][j]);
			}
		}
		dp = next;
	}
	return result;
}

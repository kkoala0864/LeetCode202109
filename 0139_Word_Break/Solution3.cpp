#include <Solution.h>
#include <iostream>
#include <vector>
#include <unordered_set>

using std::unordered_set;
using std::vector;

bool Solution::wordBreak3(string s, vector<string> &wordDict) {
	if (s.empty())
		return false;
	vector<vector<string>> map(26, vector<string>());
	vector<bool> dp(s.size(), false);
	for (const auto &iter : wordDict) {
		map[iter[0] - 'a'].emplace_back(iter);
	}

	for (int i = 0; i < s.size(); ++i) {
		for (const auto &iter : map[s[i] - 'a']) {
			if ((i + iter.size() - 1) >= s.size())
				continue;
			int j = 0;
			for (; j < iter.size(); ++j)
				if (s[i + j] != iter[j])
					break;
			if (j == iter.size()) {
				bool local = i == 0 ? true : true & dp[i - 1];
				dp[i + j - 1] = dp[i + j - 1] | local;
			}
		}
	}
	return dp[s.size() - 1];
}

#include <Solution.h>
#include <iostream>

vector<string> Solution::wordBreak2(string s, vector<string>& wordDict) {
	vector<vector<string>> dp(s.size() + 1, vector<string>());
	dp[0].push_back("");

	for (int i = 0 ; i < s.size() ; ++i) {
		for (const auto& w : wordDict) {
			if ((i+1) < w.size()) continue;
			int lastIdx = i - w.size() + 1;
			string cur = s.substr(lastIdx, w.size());
			if (cur != w) continue;
			for (auto v : dp[lastIdx]) {
				string tmp = v;
				tmp += tmp.empty() ? w : (" " + w);
				dp[i+1].emplace_back(tmp);
			}

		}
	}
	return dp.back();
}

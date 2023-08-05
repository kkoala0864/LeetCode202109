#include <Solution.h>
#include <iostream>
#include <vector>
#include <unordered_set>

using std::vector;
using std::unordered_set;

bool Solution::wordBreak4(string s, vector<string>& wordDict) {
	vector<bool> dp(s.size() + 1, false);
	dp[0] = true;

	for (int i = 1 ; i <= s.size() ; ++i) {
		for (const auto& w : wordDict) {
			if (i >= w.size()) {
				string tmpStr = s.substr(i - w.size(), w.size());
				if (tmpStr == w) {
					dp[i] = dp[i-w.size()];
				}
			}
			if (dp[i]) break;
		}
	}
	return dp.back();
}



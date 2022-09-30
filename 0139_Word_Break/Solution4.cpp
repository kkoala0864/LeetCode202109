#include <Solution.h>
#include <iostream>
#include <vector>
#include <unordered_set>

using std::vector;
using std::unordered_set;

bool Solution::wordBreak4(string s, vector<string>& wordDict) {
	vector<bool> dp(s.size() + 1, false);
	dp[0] = true;

	for (int i = 0 ; i < s.size() ; ++i) {
		for (const auto& word : wordDict) {
			int wSize = word.size();
			if (i < wSize - 1) continue;
			if (dp[i - wSize + 1]) {
				string cmpStr = s.substr(i - wSize + 1, wSize);
				if (cmpStr == word) dp[i + 1] = true;
			}
			if (dp[i + 1]) continue;
		}
	}
	return dp[s.size()];
}



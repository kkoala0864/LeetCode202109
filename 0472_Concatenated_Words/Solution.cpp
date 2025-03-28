#include <Solution.h>
#include <iostream>
#include <unordered_set>

using std::unordered_set;

vector<string> Solution::findAllConcatenatedWordsInADict(vector<string> &words) {
	vector<string> result;
	unordered_set<string> uSet;
	for (const auto &v : words)
		uSet.emplace(v);

	for (const auto &s : words) {
		int size = s.size();
		vector<bool> dp(size + 1, false);
		dp[0] = true;
		for (int i = 1; i <= size; ++i) {
			for (int j = (i == size ? 1 : 0); !dp[i] && j < i; ++j) {
				dp[i] = dp[j] && uSet.count(s.substr(j, i - j));
			}
		}
		if (dp[size])
			result.emplace_back(s);
	}
	return result;
}

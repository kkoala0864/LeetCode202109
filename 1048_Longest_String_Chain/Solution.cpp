#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using std::max;
using std::sort;
using std::unordered_map;

int Solution::longestStrChain(vector<string> &words) {
	unordered_map<string, int> dp;
	int result = 0;

	auto cmp = [](string &lhs, string &rhs) { return lhs.size() < rhs.size(); };
	sort(words.begin(), words.end(), cmp);

	for (const auto &w : words) {
		for (int i = 0; i < w.size(); ++i) {
			string tmp = w;
			tmp.erase(i, 1);
			if (dp.find(tmp) != dp.end())
				dp[w] = max(dp[w], dp[tmp] + 1);
			else
				dp[w] = max(dp[w], 1);
		}
		result = max(dp[w], result);
	}
	return result;
}

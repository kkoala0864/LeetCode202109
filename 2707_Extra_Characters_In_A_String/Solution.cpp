#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::max;

int Solution::minExtraChar(string s, vector<string>& dictionary) {
	vector<vector<string>> dics(26, vector<string>());

	for (const auto& d : dictionary) {
		dics[d.back() - 'a'].emplace_back(d);
	}

	vector<int> dp(s.size() + 1, 0);
	vector<int> preMax(s.size() + 1, 0);
	int maxVal = 0;

	for (int i = 0 ; i < s.size() ; ++i) {
		int idx = s[i] - 'a';
		if (dics[idx].size() > 0) {
			for (const auto& d : dics[idx]) {
				int ds = d.size();
				if (i < (ds - 1)) continue;
				string curStr = s.substr(i - ds + 1, ds);
				if (curStr != d) continue;
				dp[i + 1] = max(dp[i + 1], preMax[i - ds + 1] + ds);
			}
		}
		maxVal = max(maxVal, dp[i + 1]);
		preMax[i + 1] = maxVal;
	}
	return s.size() - preMax.back();
}

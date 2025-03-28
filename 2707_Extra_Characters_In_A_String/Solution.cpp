#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::max;

int Solution::minExtraChar(string s, vector<string> &dictionary) {
	int size = s.size();

	vector<int> dp(size + 1, 0);
	vector<int> preMax(size + 1, 0);
	vector<vector<string>> dic(26, vector<string>());

	for (const auto &d : dictionary)
		dic[d.back() - 'a'].emplace_back(d);

	for (int i = 0; i < s.size(); ++i) {
		for (const auto &d : dic[s[i] - 'a']) {
			int ds = d.size();
			if ((ds - 1) > i)
				continue;
			string cur = s.substr(i - ds + 1, ds);
			if (cur != d)
				continue;
			dp[i + 1] = max(dp[i + 1], preMax[i - ds + 1] + ds);
		}
		preMax[i + 1] = max(dp[i + 1], preMax[i]);
	}
	return size - preMax.back();
}

#include <Solution.h>
#include <iostream>
#include <unordered_set>
#include <algorithm>

using std::max;
using std::unordered_set;

void dfs(int idx, const string &s, int cnt, int &result, unordered_set<string> &ss) {
	if (idx == s.size()) {
		result = max(result, cnt);
		return;
	}

	string curStr;
	for (int i = idx; i < s.size(); ++i) {
		curStr.push_back(s[i]);
		if (ss.count(curStr))
			continue;
		ss.emplace(curStr);
		dfs(i + 1, s, cnt + 1, result, ss);
		ss.erase(curStr);
	}
}

int Solution::maxUniqueSplit(string s) {
	unordered_set<string> ss;
	int result = 0;
	dfs(0, s, 0, result, ss);
	return result;
}

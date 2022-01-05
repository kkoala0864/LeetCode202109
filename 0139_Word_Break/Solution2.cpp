#include <Solution.h>
#include <iostream>
#include <vector>
#include <unordered_set>

using std::vector;
using std::unordered_set;

bool dfs(const unordered_set<string>& uSet, vector<bool>& isFind, const string& s, int idx) {
	if (idx == s.size()) return true;

	if (!isFind[idx]) return false;

	for (int i = idx ; i < s.size() ; ++i) {
		string substr = s.substr(idx, i - idx + 1);
		if (uSet.find(substr) != uSet.end()) {
			bool ret = dfs(uSet, isFind, s, i + 1);
			if (ret) return true;
		}
	}
	isFind[idx] = false;
	return false;
}

bool Solution::wordBreak2(string s, vector<string>& wordDict) {
	unordered_set<string> uSet;
	vector<bool> isFind(s.size(), true);
	for (const auto& iter : wordDict) uSet.emplace(iter);
	return dfs(uSet, isFind, s, 0);
}

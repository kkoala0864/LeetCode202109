#include <Solution.h>
#include <iostream>

// Clarify:
// 1. every element must be used at least once ?

using std::min;
using std::cout;
using std::endl;
// ["applepenapple"] ["apple", "pen"]
/*
bool recur(const string& s, int idx, const vector<vector<string>>& wMap) {
	if (idx > s.size()) return false;
	if (idx == s.size()) return true;

	if (wMap[s[idx]-'a'].empty()) return false;

	bool localResult = false;
	for (const auto& iter : wMap[s[idx]-'a']) {
		if ((idx+iter.size()) > s.size()) continue;
		int i = 0;
		for (; i < iter.size() ; ++i) if (s[idx+i] != iter[i]) break;
		if (i == iter.size()) localResult |= recur(s, idx+iter.size(), wMap);
	}
	return localResult;
}

bool Solution::wordBreak(string s, vector<string>& wordDict) {
	vector<vector<string>> wMap(26, vector<string>());
	for (const auto& iter : wordDict) wMap[iter[0]-'a'].emplace_back(iter);
	return recur(s, 0, wMap);
}
*/

bool Solution::wordBreak(string s, vector<string>& wordDict) {
	vector<vector<string>> wMap(26, vector<string>());
	vector<bool> dp(s.size(), false);
	for (const auto& iter : wordDict) wMap[iter[0]-'a'].emplace_back(iter);

	for (int i = 0 ; i < s.size() ; ++i) {
		for (const auto& iter : wMap[s[i] - 'a']) {
			if ((i + iter.size() - 1) >= s.size()) continue;
			int idx = 0;
			for (; idx < iter.size() ; ++idx) if (s[i+idx] != iter[idx]) break;
			if (idx == iter.size()) {
				bool localResult = (i == 0) ? true : true & dp[i - 1];
				dp[i+idx-1] = dp[i+idx-1] | localResult;
			}
		}
	}
	return dp[s.size() - 1];
}

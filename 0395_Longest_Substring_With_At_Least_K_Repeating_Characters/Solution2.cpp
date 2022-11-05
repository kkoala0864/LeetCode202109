#include <Solution.h>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using std::vector;
using std::max;
using std::unordered_set;

void dfs(const string& s, int k, int& result) {
	if (s.empty() || s.size() < k) return;
	vector<int> cnt(26, 0);
	for (const auto& c : s) ++cnt[c-'a'];
	unordered_set<char> uSet;
	for (int i = 0 ; i < 26 ; ++i) {
		if (cnt[i] == 0) continue;
		if (cnt[i] < k) uSet.emplace(i + 'a');
	}
	if (uSet.empty()) {
		result = max(result, (int)s.size());
		return;
	}

	int l = 0;
	for (int i = 0 ; i < s.size() ; ++i) {
		if (uSet.count(s[i])) {
			dfs(s.substr(l, i - l), k, result);
			l = i+1;
		}
	}
	dfs(s.substr(l), k, result);
}

int Solution::longestSubstring2(string s, int k) {
	int result = 0;
	dfs(s, k, result);
	return result;
}

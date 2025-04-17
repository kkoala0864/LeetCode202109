#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

bool check(const string& s, const string& sub, int start, unordered_map<char, unordered_set<char>>& m) {
	for (int i = 0 ; i < sub.size() ; ++i) {
		if (s[start + i] == sub[i] || m[s[start+i]].count(sub[i])) continue;
		return false;
	}
	return true;
}

bool Solution::matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
	if (s.find(sub) != string::npos) return true;

	int usize = sub.size();
	unordered_map<char, unordered_set<char>> m;
	for (const auto& map : mappings) {
		m[map[1]].emplace(map[0]);
	}

	for (int i = 0 ; i <= s.size() - usize ; ++i) {
		if (check(s, sub, i, m)) return true;
	}
	return false;
}

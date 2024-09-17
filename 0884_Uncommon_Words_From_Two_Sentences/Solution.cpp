#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

void parse(string& s, unordered_map<string, int>& m) {
	string cur;
	for (int i = 0 ; i < s.size() ; ++i) {
		if (s[i] == ' ') {
			++m[cur];
			cur = "";
		} else {
			cur.push_back(s[i]);
		}
	}
	if (!cur.empty()) {
		++m[cur];
	}
}

vector<string> Solution::uncommonFromSentences(string s1, string s2) {
	unordered_map<string, int> m1, m2;

	parse(s1, m1);
	parse(s2, m2);

	vector<string> result;
	for (const auto& e : m1) {
		if (e.second == 1 && m2.count(e.first) == 0) result.emplace_back(e.first);
	}
	for (const auto& e : m2) {
		if (e.second == 1 && m1.count(e.first) == 0) result.emplace_back(e.first);
	}
	return result;
}

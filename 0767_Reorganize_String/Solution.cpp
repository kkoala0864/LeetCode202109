#include <Solution.h>
#include <iostream>
#include <vector>
#include <map>

using std::map;
using std::vector;

string Solution::reorganizeString(string s) {
	vector<int> cnt(26, 0);
	int h = s.size() / 2;
	for (const auto &c : s)
		++cnt[c - 'a'];

	map<int, vector<char>, std::greater<int>> m;

	for (int i = 0; i < 26; ++i) {
		m[cnt[i]].emplace_back('a' + i);
	}
	if (s.size() - m.begin()->first < (m.begin()->first - 1)) {
		return "";
	}

	string ss;
	for (const auto &e : m) {
		for (const auto &c : e.second) {
			ss += string(e.first, c);
		}
	}

	int l = 0, i = 0;
	int r = h + (s.size() & 1);

	while (i < s.size()) {
		s[i++] = ss[l++];
		if (i < s.size()) {
			s[i++] = ss[r++];
		}
	}
	return s;
}

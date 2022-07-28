#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

bool Solution::isAnagram3(string s, string t) {
	if (s.size() != t.size()) return false;
	vector<int> cnt(26, 0);
	for (const auto& c : s) ++cnt[c-'a'];

	for (const auto& c : t) {
		if (cnt[c-'a'] == 0) return false;
		--cnt[c-'a'];
	}
	return true;
}

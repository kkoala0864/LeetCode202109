#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

bool Solution::checkInclusion2(string s1, string s2) {
	if (s2.size() < s1.size()) return false;
	vector<int> cnt(26, 0);

	for (const auto& c : s1) ++cnt[c-'a'];

	for (int i = 0 ; i < s1.size() - 1 ; ++i) --cnt[s2[i]-'a'];

	for (int i = s1.size() - 1 ; i < s2.size() ; ++i) {
		--cnt[s2[i]-'a'];
		if (i >= s1.size()) ++cnt[s2[i-s1.size()]-'a'];
		int ci = 0;
		for (; ci < 26 ; ++ci) if (cnt[ci] != 0) break;
		if (ci == 26) return true;
	}
	return false;
}

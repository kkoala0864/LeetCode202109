#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

bool Solution::isAnagram2(string s, string t) {
	if (s.size() != t.size()) return false;
	vector<int> map(26, 0);

	for (const auto& iter : s) ++map[iter-'a'];
	for (const auto& iter : t) {
		if (map[iter-'a'] == 0) return false;
		--map[iter-'a'];
	}
	return true;
}

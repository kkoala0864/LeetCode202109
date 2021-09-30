#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

bool Solution::isAnagram(string s, string t) {
	if (s.size() != t.size()) return false;
	vector<int> sMap(26, 0);

	for (const auto& iter : s) ++sMap[iter-'a'];

	for (const auto& iter : t) {
		if (sMap[iter-'a'] > 0) {
			--sMap[iter-'a'];
		} else {
			return false;
		}
	}
	return true;
}

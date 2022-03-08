#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

bool Solution::isOneEditDistance2(string s, string t) {
	if (s == t) return false;
	string ls = s.size() > t.size() ? s : t;
	string ss = ls == s ? t : s;
	if ((ls.size() - ss.size()) > 1) return false;

	int liter = 0, siter = 0;
	int cnt = 0;
	while (liter < ls.size()) {
		if (ls[liter] != ss[siter]) {
			++cnt;
			if (cnt > 1) return false;
			++liter;
			if (s.size() == t.size()) ++siter;
		} else {
			++liter;
			++siter;
		}
	}
	return cnt == 1;
}

#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

// aba, abc
// ab, acb
// abc, acd
// ac, adb

bool Solution::isOneEditDistance2(string s, string t) {
	if (s == t)
		return false;
	int sn = s.size();
	int tn = t.size();
	if (abs(sn - tn) > 1)
		return false;

	string longer = sn > tn ? s : t;
	string shorter = longer == s ? t : s;

	int li = 0, si = 0;
	int cnt = 0;

	while (li < longer.size() && cnt < 2) {
		if (longer[li] != shorter[si]) {
			++cnt;
			if (tn != sn)
				--si;
		}
		++li;
		++si;
	}
	return cnt == 1;
}

#include <Solution.h>
#include <iostream>

bool Solution::isSubsequence2(string s, string t) {
	int si = 0, ti = 0;
	while (ti < t.size()) {
		if (s[si] == t[ti])
			++si;
		++ti;
	}
	return si == s.size();
}

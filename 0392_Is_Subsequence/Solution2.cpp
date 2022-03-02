#include <Solution.h>
#include <iostream>

bool Solution::isSubsequence2(string s, string t) {
	if (s.empty() && t.empty()) return true;
	if (s.size() > t.size()) return false;
	int sIter = 0, tIter = 0;
	while (sIter < s.size()) {
		 while (tIter < t.size() && s[sIter] != t[tIter]) ++tIter;
		 if (tIter == t.size()) return false;
		 ++tIter;
		 ++sIter;
	}
	return true;
}

#include <Solution.h>
#include <iostream>

bool Solution::backspaceCompare3(string s, string t) {
	int si = 0, ti = 0;
	for (int i = 0 ; i < s.size() ; ++i) {
		if (s[i] == '#') {
			if (si > 0) --si;
		} else {
			s[si++] = s[i];
		}
	}
	for (int i = 0 ; i < t.size() ; ++i) {
		if (t[i] == '#') {
			if (ti > 0) --ti;
		} else {
			t[ti++] = t[i];
		}
	}

	if (si != ti) return false;
	for (int i = 0 ; i < si ; ++i) {
		if (s[i] != t[i]) return false;
	}
	return true;
}

#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

bool Solution::backspaceCompare3(string s, string t) {
	string s1, t1;
	int size = max(s.size(), t.size());
	for (int i = 0 ; i < size ; ++i) {
		if (i < s.size()) {
			if (s[i] != '#') {
				s1.push_back(s[i]);
			} else {
				if (!s1.empty()) s1.pop_back();
			}
		}
		if (i < t.size()) {
			if (t[i] != '#') {
				t1.push_back(t[i]);
			} else {
				if (!t1.empty()) t1.pop_back();
			}
		}
	}
	return s1 == t1;
}

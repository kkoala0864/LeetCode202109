#include <Solution.h>
#include <iostream>

bool Solution::backspaceCompare(string s, string t) {
	string ss, ts;

	for (const auto& iter : s) {
		if (iter != '#') {
			ss.push_back(iter);
		} else {
			if (!ss.empty()) ss.pop_back();
		}
	}

	for (const auto& iter : t) {
		if (iter != '#') {
			ts.push_back(iter);
		} else {
			if (!ts.empty()) ts.pop_back();
		}
	}

	if (ss.size() != ts.size()) return false;
	return ss == ts;
}

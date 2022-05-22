#include <Solution.h>
#include <iostream>

void count(const string& s, int l, int r, int& result) {
	while (l >= 0 && r < s.size()) {
		if (s[l] == s[r]) ++result;
		else return;
		--l;
		++r;
	}
}

int Solution::countSubstrings3(string s) {
	int result = 0;

	for (int i = 0 ; i < s.size() ; ++i) {
		count(s, i, i, result);
		if (i < s.size() - 1) {
			count(s, i, i+1, result);
		}
	}
	return result;
}

#include <Solution.h>
#include <iostream>

void check(const string &s, int start, int end, int &result) {
	while (start >= 0 && end < s.size()) {
		if (s[start] == s[end])
			++result;
		else
			break;
		--start;
		++end;
	}
}

int Solution::countSubstrings2(string s) {
	int result = 0;
	for (int i = 0; i < s.size(); ++i) {
		check(s, i, i, result);
		if (i < s.size() - 1)
			check(s, i, i + 1, result);
	}
	return result;
}

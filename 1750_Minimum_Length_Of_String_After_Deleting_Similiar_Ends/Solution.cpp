#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int Solution::minimumLength(string s) {
	int l = 0, r = s.size() - 1;

	while (l < r) {
		if (s[l] != s[r]) break;
		while (l < r && s[l] == s[l+1]) ++l;
		while (l < r && s[r] == s[r-1]) --r;
		++l;
		--r;
	}
	return max(0, r - l + 1);
}

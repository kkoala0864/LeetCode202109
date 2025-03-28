#include <Solution.h>
#include <iostream>

int Solution::lengthOfLastWord(string s) {
	int l = 0, r = s.size() - 1;
	int result = 0;
	while (r >= l && s[r] == ' ')
		--r;
	while (l <= r) {
		if (s[l] == ' ')
			result = 0;
		else
			++result;
		++l;
	}
	return result;
}

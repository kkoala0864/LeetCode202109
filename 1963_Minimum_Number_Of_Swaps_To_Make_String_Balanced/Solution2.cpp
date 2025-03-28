#include <Solution.h>
#include <iostream>

int Solution::minSwaps2(string s) {
	int l = 0, r = s.size() - 1;

	int lcnt = 0, rcnt = 0;
	int result = 0;

	while (l < r) {
		while (l < r) {
			lcnt += s[l] == '[' ? 1 : -1;
			if (lcnt < 0)
				break;
			++l;
		}
		while (l < r) {
			rcnt += s[r] == ']' ? 1 : -1;
			if (rcnt < 0)
				break;
			--r;
		}
		if (l < r) {
			lcnt = rcnt = 1;
			++l;
			--r;
			++result;
		}
	}
	return result;
}

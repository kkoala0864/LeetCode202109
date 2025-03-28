#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int Solution::countKConstraintSubstrings(string s, int k) {
	int result = 0;
	int l = 0;
	int cnt0 = 0, cnt1 = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '0')
			++cnt0;
		else
			++cnt1;

		while (cnt0 > k && cnt1 > k) {
			if (s[l] == '0')
				--cnt0;
			else
				--cnt1;
			++l;
		}

		result += ((i - l) + 1);
	}
	return result;
}

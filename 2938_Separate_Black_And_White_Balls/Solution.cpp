#include <Solution.h>
#include <iostream>

using std::swap;
long long Solution::minimumSteps(string s) {
	long long result = 0;
	int l = 0, r = s.size() - 1;
	while (l < r) {
		while (l < r && s[l] == '0')
			++l;
		while (l < r && s[r] == '1')
			--r;
		if (l < r) {
			result += (r - l);
			++l;
			--r;
		}
	}
	return result;
}

#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int Solution::equalSubstring(string s, string t, int maxCost) {
	int result = 0;

	int l = 0;
	for (int i = 0 ; i < s.size() ; ++i) {
		maxCost -= abs(s[i] - t[i]);
		while (maxCost < 0 && l < i) {
			maxCost += abs(s[l] - t[l]);
			++l;
		}
		if (maxCost >= 0) {
			result = max(result, i - l + 1);
		}
	}
	return result;
}

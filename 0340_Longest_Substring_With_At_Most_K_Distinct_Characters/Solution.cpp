#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <vector>

using std::max;
using std::vector;

int Solution::lengthOfLongestSubstringKDistinct(string s, int k) {
	if (k == 0)
		return 0;
	int cnt = 0;
	int start = 0;
	int end = 0;
	int result = 0;
	int size = s.size();
	vector<int> uMap(128, 0);

	while (end < size) {
		if (cnt <= k) {
			if (uMap[s[end]] == 0)
				++cnt;
			++uMap[s[end]];
			++end;
		} else {
			--uMap[s[start]];
			if (uMap[s[start]] == 0)
				--cnt;
			++start;
		}
		if (cnt <= k)
			result = max(result, end - start);
	}

	if (cnt <= k)
		result = max(result, end - start);
	return result;
}

#include <Solution.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using std::vector;
using std::max;

int Solution::lengthOfLongestSubstring2(string s) {
	if (s.empty()) return 0;
	vector<int> location(128, -1);
	int result = 0;

	int start = 0;
	int end = 0;
	while (end < s.size()) {
		if (location[s[end]] != -1) {
			int lastIdx = location[s[end]];
			result = max(result, end - start);
			for (int i = start ; i < lastIdx ; ++i) {
				location[s[i]] = -1;
			}
			start = lastIdx + 1;
		}
		location[s[end]] = end;
		++end;
	}
	result = max(result, end - start);
	return result;
}

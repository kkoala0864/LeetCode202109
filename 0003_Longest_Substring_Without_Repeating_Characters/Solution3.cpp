#include <Solution.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using std::max;
using std::vector;

int Solution::lengthOfLongestSubstring3(string s) {
	if (s.empty())
		return 0;
	int start = 0, end = 0;
	vector<int> idx(128, -1);
	int result = 0;
	while (end < s.size()) {
		int ch = s[end] - ' ';
		if (idx[ch] == -1) {
			idx[ch] = end;
		} else {
			result = max(result, end - start);
			while (start <= idx[ch]) {
				int loc = s[start] - ' ';
				idx[loc] = -1;
				++start;
			}
			idx[ch] = end;
		}
		++end;
	}
	result = max(result, end - start);
	return result;
}

#include <Solution.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using std::max;
using std::vector;

int Solution::lengthOfLongestSubstring4(string s) {
	vector<int> cnt(128, 0);
	int result = 0;

	int l = 0;
	for (int i = 0; i < s.size(); ++i) {
		char c = s[i];
		while (l < i && cnt[c - ' '] > 0) {
			--cnt[s[l] - ' '];
			++l;
		}
		++cnt[c - ' '];
		result = max(result, i - l + 1);
	}
	return result;
}

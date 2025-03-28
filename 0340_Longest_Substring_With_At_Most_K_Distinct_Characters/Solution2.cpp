#include <Solution.h>
#include <iostream>
#include <vector>
#include <algorithm>

using std::max;
using std::vector;

int Solution::lengthOfLongestSubstringKDistinct2(string s, int k) {
	if (k <= 0 || s.empty())
		return 0;
	vector<int> cnt(128, 0);
	int start = 0, iter = 0, result = 0;
	while (iter < s.size()) {
		if (cnt[s[iter]] == 0) {
			--k;
			while (start < iter && k < 0) {
				--cnt[s[start]];
				if (cnt[s[start]] == 0)
					++k;
				++start;
			}
		}
		++cnt[s[iter]];
		result = max(result, iter - start + 1);
		++iter;
	}
	return result;
}

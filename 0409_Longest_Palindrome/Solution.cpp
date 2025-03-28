#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;

int Solution::longestPalindrome(string s) {
	vector<int> cnt(128, 0);

	for (const auto &c : s)
		++cnt[c - 'A'];

	int result = 0;
	for (int i = 0; i < cnt.size(); ++i) {
		if ((cnt[i] & 1) && (result & 1) == 0) {
			result += cnt[i];
		} else {
			result += cnt[i] & 1 ? cnt[i] - 1 : cnt[i];
		}
	}
	return result;
}

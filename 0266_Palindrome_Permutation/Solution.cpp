#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

bool Solution::canPermutePalindrome(string s) {
	vector<int> cnt(26, 0);

	for (const auto &c : s)
		++cnt[c - 'a'];

	int odd_cnt = 0;
	for (const auto &v : cnt) {
		if (v & 1)
			++odd_cnt;
	}
	return odd_cnt < 2;
}

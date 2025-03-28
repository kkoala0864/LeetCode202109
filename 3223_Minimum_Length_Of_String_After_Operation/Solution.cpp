#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

int Solution::minimumLength(string s) {

	vector<int> cnt(26, 0);
	for (const auto &c : s)
		++cnt[c - 'a'];
	int result = 0;
	for (const auto &v : cnt) {
		if (v < 3) {
			result += v;
		} else {
			int mod = v % 2;
			result += (mod == 0 ? 2 : 1);
		}
	}
	return result;
}

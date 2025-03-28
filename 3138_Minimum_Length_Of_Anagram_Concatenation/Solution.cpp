#include <Solution.h>
#include <iostream>
#include <vector>
#include <numeric>

using std::gcd;
using std::vector;

int Solution::minAnagramLength(string s) {
	vector<int> cnt(26, 0);
	for (const auto &c : s)
		++cnt[c - 'a'];

	int times = cnt[0];

	for (int i = 1; i < 26; ++i) {
		times = gcd(times, cnt[i]);
	}

	int result = 0;
	for (int i = 0; i < 26; ++i) {
		result += cnt[i] / times;
	}

	return result;
}

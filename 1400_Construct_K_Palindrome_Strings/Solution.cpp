#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

bool Solution::canConstruct(string s, int k) {
	vector<int> cnt(26, 0);

	for (const auto& c : s) {
		++cnt[c-'a'];
	}
	int odd = 0;
	for (int i = 0 ; i < 26 ; ++i) {
		if (cnt[i] & 1) ++odd;
	}
	if (odd > k) return false;
	return s.size() >= k;
}

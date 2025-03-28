#include <Solution.h>
#include <iostream>

bool Solution::isOneEditDistance(string s, string t) {
	int bIdx = 0;
	int sIdx = 0;
	int cnt = 0;

	string big = s.size() > t.size() ? s : t;
	string small = s.size() > t.size() ? t : s;

	while (bIdx < big.size() && sIdx < small.size()) {
		if (cnt > 1)
			return false;
		if (big[bIdx] == small[sIdx]) {
			++bIdx;
			++sIdx;
		} else {
			if (big.size() == small.size())
				++sIdx;
			++cnt;
			++bIdx;
		}
	}
	cnt += big.size() - bIdx;
	return cnt == 1;
}

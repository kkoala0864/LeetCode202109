#include <Solution.h>
#include <iostream>
#include <set>
#include <algorithm>

using std::max;
using std::min;
using std::set;

int Solution::kEmptySlots(vector<int> &bulbs, int k) {
	if (bulbs.size() < (k + 2))
		return -1;

	set<int> s;
	for (int i = 0; i < bulbs.size(); ++i) {
		s.emplace(bulbs[i]);
		auto it = s.find(bulbs[i]);

		if (it != s.begin()) {
			auto prev = it;
			--prev;
			if (bulbs[i] - *prev == (k + 1))
				return i + 1;
		}

		if (it != s.end()) {
			auto next = it;
			++next;
			if (next != s.end() && *next - bulbs[i] == (k + 1))
				return i + 1;
		}
	}
	return -1;
}

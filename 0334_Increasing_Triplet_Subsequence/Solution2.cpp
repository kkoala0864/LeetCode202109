#include <Solution.h>
#include <iostream>

// list length ?
// val range ?
// duplicate val ?
// 1, 5, 3, 4, 2, 6
// 0, 0, 3, 0, 1, 4
// 4, 5, 0, 6

bool Solution::increasingTriplet2(vector<int> &nums) {
	vector<int> list;

	for (const auto &v : nums) {
		auto idx = lower_bound(list.begin(), list.end(), v) - list.begin();
		if (idx == list.size())
			list.emplace_back(v);
		else
			list[idx] = v;
		if (list.size() >= 3)
			return true;
	}
	return false;
}

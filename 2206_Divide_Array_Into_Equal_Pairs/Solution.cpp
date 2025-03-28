#include <Solution.h>
#include <iostream>

bool Solution::divideArray(vector<int> &nums) {
	vector<int> cnt(501, 0);
	for (const auto &v : nums)
		++cnt[v];
	for (const auto &v : cnt)
		if (v & 1)
			return false;
	return true;
}

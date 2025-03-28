#include <Solution.h>
#include <iostream>

int Solution::largestUniqueNumber(vector<int> &nums) {
	vector<int> cnt(1001, 0);
	for (const auto &v : nums)
		++cnt[v];

	for (int i = 1000; i >= 0; --i) {
		if (cnt[i] == 1)
			return i;
	}
	return -1;
}

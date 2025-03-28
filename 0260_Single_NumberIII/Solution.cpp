#include <Solution.h>
#include <iostream>

vector<int> Solution::singleNumber(vector<int> &nums) {
	long long bitmask = 0;
	for (const auto &iter : nums) {
		bitmask ^= iter;
	}

	long long diff = bitmask & -bitmask;
	long long x = 0;
	for (const auto &iter : nums) {
		if (iter & diff) {
			x ^= iter;
		}
	}
	return {(int)x, static_cast<int>(x ^ bitmask)};
}

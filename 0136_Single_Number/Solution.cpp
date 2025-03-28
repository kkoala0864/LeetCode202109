#include <Solution.h>
#include <iostream>

int Solution::singleNumber(vector<int> &nums) {
	int result = 0;
	for (const auto &iter : nums) {
		result ^= iter;
	}
	return result;
}

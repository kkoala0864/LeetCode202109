#include <Solution.h>
#include <iostream>

int Solution::missingNumber(vector<int> &nums) {
	int size = nums.size();
	int total = (1 + size) * size / 2;
	for (const auto &iter : nums) {
		total -= iter;
	}
	return total;
}

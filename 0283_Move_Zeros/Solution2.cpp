#include <Solution.h>
#include <iostream>

using std::swap;

void Solution::moveZeroes2(vector<int>& nums) {
	int i = 0;
	int idx = 0;
	while (idx < nums.size()) {
		if (nums[idx] != 0) {
			swap(nums[i], nums[idx]);
			++i;
		}
		++idx;
	}
}

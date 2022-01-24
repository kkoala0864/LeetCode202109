#include <Solution.h>
#include <iostream>

using std::swap;
int Solution::removeElement2(vector<int>& nums, int val) {
	int i = 0;
	int idx = 0;
	while (idx < nums.size()) {
		if (nums[idx] != val) {
			swap(nums[i], nums[idx]);
			++i;
		}
		++idx;
	}
	return i;
}

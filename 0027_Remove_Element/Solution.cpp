#include <Solution.h>
#include <iostream>

int Solution::removeElement(vector<int> &nums, int val) {
	int idx = 0;
	int iter = 0;
	while (iter < nums.size()) {
		if (nums[iter] != val) {
			nums[idx] = nums[iter];
			++idx;
		}
		++iter;
	}
	return idx;
}

#include <Solution.h>
#include <iostream>

int Solution::removeDuplicates(vector<int>& nums) {
	if (nums.size() < 2) return nums.size();
	int idx = 0;
	int iter = 1;
	int cnt = 0;
	while (iter < nums.size()) {
		if (nums[idx] != nums[iter]) {
			cnt = 0;
			++idx;
			nums[idx] = nums[iter];
		} else {
			if (cnt < 1) {
				++idx;
				nums[idx] = nums[iter];
			}
			++cnt;
		}
		++iter;
	}

	return idx + 1;
}

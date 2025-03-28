#include <Solution.h>
#include <iostream>

int Solution::removeDuplicates2(vector<int> &nums) {
	int i = 0, iter = 1;
	int cnt = 0;
	while (iter < nums.size()) {
		if (nums[i] != nums[iter]) {
			cnt = 0;
			++i;
			nums[i] = nums[iter];
		} else {
			if (cnt < 1) {
				++i;
				nums[i] = nums[iter];
			}
			++cnt;
		}
		++iter;
	}
	return i + 1;
}

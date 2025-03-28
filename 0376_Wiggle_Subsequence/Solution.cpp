#include <Solution.h>
#include <iostream>

int Solution::wiggleMaxLength(vector<int> &nums) {
	if (nums.size() < 2)
		return nums.size();
	int iter = 0;
	int cnt = 0;
	if (nums[0] == nums[1]) {
		while (iter < nums.size() - 1 && nums[iter] == nums[iter + 1])
			++iter;
	}

	int action = nums[iter] > nums[iter + 1];
	while (iter < nums.size() - 1) {
		if ((action && nums[iter] > nums[iter + 1]) || (!action && nums[iter] < nums[iter + 1])) {
			++iter;
			++cnt;
			action ^= 1;
		} else
			++iter;
	}
	return cnt + 1;
}

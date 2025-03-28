#include <Solution.h>
#include <iostream>

vector<int> Solution::applyOperations(vector<int> &nums) {
	vector<int> result(nums.size(), 0);

	int ri = 0;
	for (int i = 0; i < nums.size() - 1; ++i) {
		if (nums[i] == 0)
			continue;
		if (nums[i] == nums[i + 1]) {
			result[ri++] = (nums[i] << 1);
			nums[i + 1] = 0;
		} else {
			result[ri++] = nums[i];
		}
	}
	if (nums.back() != 0)
		result[ri] = nums.back();
	return result;
}

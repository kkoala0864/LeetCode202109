#include <Solution.h>
#include <iostream>

int Solution::minIncrementForUnique(vector<int> &nums) {

	sort(nums.begin(), nums.end());

	int result = 0;
	for (int i = 1; i < nums.size(); ++i) {
		if (nums[i - 1] < nums[i])
			continue;
		result += (nums[i - 1] - nums[i] + 1);
		nums[i] = nums[i - 1] + 1;
	}
	return result;
}

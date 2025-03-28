#include <Solution.h>
#include <iostream>

int Solution::firstMissingPositive(vector<int> &nums) {
	int n = nums.size();
	for (auto &val : nums) {
		if (val == 0 || val < 0)
			val = n + 1;
	}

	for (int i = 0; i < n; ++i) {
		int idx = abs(nums[i]);
		if (idx < (n + 1)) {
			nums[idx - 1] = nums[idx - 1] > 0 ? -nums[idx - 1] : nums[idx - 1];
		}
	}

	for (int i = 0; i < n; ++i) {
		if (nums[i] > 0) {
			return i + 1;
		}
	}
	return n + 1;
}

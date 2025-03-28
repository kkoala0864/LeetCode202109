#include <Solution.h>
#include <iostream>

vector<int> Solution::findDuplicates3(vector<int> &nums) {
	vector<int> result;
	for (int i = 0; i < nums.size(); ++i) {
		int idx = nums[i] < 0 ? -nums[i] - 1 : nums[i] - 1;
		if (nums[idx] < 0)
			result.emplace_back(idx + 1);
		else {
			nums[idx] = -nums[idx];
		}
	}
	return result;
}

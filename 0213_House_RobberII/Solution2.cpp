#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
using std::swap;

int rb(vector<int>& nums, int start, int end) {
	int prev = 0;
	int cur = nums[start];
	for (int i = start + 1 ; i <= end ; ++i) {
		prev = max(nums[i] + prev, cur);
		swap(prev, cur);
	}
	return cur;
}

int Solution::rob2(vector<int>& nums) {
	if (nums.size() == 1) return nums[0];
	if (nums.size() == 2) return max(nums[0], nums[1]);
	if (nums.size() == 3) return max({nums[0], nums[1], nums[2]});
	return max(nums[0] + rb(nums, 2, nums.size() - 2), rb(nums, 1, nums.size() - 1));
}

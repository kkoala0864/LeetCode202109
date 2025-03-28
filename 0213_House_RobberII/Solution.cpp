#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
using std::swap;

int nonCycleRob(const vector<int> &nums, int start, int end) {
	int prev(0), cur(nums[start]);
	for (int i = start + 1; i <= end; ++i) {
		prev = max(cur, prev + nums[i]);
		swap(prev, cur);
	}
	return cur;
}

int Solution::rob(vector<int> &nums) {
	int size = nums.size();
	if (size == 1)
		return nums[0];
	if (size == 2)
		return max(nums[0], nums[1]);
	if (size == 3)
		return max(nums[0], max(nums[1], nums[2]));
	int noTaken = nonCycleRob(nums, 0, size - 2);
	int taken = nonCycleRob(nums, 1, size - 3) + nums[size - 1];
	return max(noTaken, taken);
}

#include <Solution.h>
#include <iostream>

bool Solution::search3(vector<int> &nums, int target) {
	int start = 0, end = nums.size() - 1;
	int mid = 0;

	while (start <= end) {
		mid = (end - start) / 2 + start;
		if (nums[mid] == target)
			return true;

		while (start < mid && nums[start] == nums[mid])
			++start;
		while (end > mid && nums[end] == nums[mid])
			--end;
		if (nums[start] <= nums[mid]) {
			if (nums[start] <= target && nums[mid] >= target) {
				end = mid - 1;
			} else {
				start = mid + 1;
			}
		} else {
			if (nums[mid] <= target && nums[end] >= target) {
				start = mid + 1;
			} else {
				end = mid - 1;
			}
		}
	}
	return false;
}

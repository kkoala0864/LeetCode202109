#include <Solution.h>
#include <iostream>

int BSearch(const vector<int> &nums, int target) {
	int start = 0;
	int end = nums.size() - 1;
	int mid = 0;

	while (start < end) {
		mid = (start + end) / 2;
		if (target > nums[mid]) {
			start = mid + 1;
		} else if (target < nums[mid]) {
			end = mid - 1;
		} else {
			return mid;
		}
	}
	return start == end ? start : mid;
}

int Solution::searchInsert(vector<int> &nums, int target) {
	int idx = BSearch(nums, target);
	return (nums[idx] >= target) ? idx : idx + 1;
}

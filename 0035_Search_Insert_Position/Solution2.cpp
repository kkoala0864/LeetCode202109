#include <Solution.h>
#include <iostream>

int Solution::searchInsert2(vector<int>& nums, int target) {
	int l = 0, r = nums.size();
	int mid = 0;

	while (l < r) {
		mid = l + ((r - l) >> 1);

		if (nums[mid] >= target) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	return nums[l] < target ? l + 1 : l;
}

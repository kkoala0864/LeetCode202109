#include <Solution.h>
#include <iostream>

//[ 4, 5, 6, 7, 0 ,1 ,2 ]

int Solution::search2(vector<int>& nums, int target) {
	int start = 0;
	int end = nums.size() - 1;

	while (start <= end) {
		int mid = (start + end) >> 1;
		if (nums[mid] == target) {
			return mid;
		} else if (nums[mid] < nums[end]) {
			if (nums[mid] < target && nums[end] >= target) {
				start = mid + 1;
			} else {
				end = mid - 1;
			}
		} else {
			if (nums[start] <= target && nums[mid] > target) {
				end = mid - 1;
			} else {
				start = mid + 1;
			}
		}
	}
	return -1;
}

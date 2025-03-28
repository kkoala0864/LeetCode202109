#include <Solution.h>
#include <iostream>

//[ 4, 5, 6, 7, 0 ,1 ,2 ]

int Solution::search3(vector<int> &nums, int target) {
	int start = 0;
	int end = nums.size() - 1;
	int mid = 0;
	while (start <= end) {
		mid = (start + end) >> 1;

		if (nums[mid] == target)
			return mid;
		else if (nums[start] <= nums[mid]) {
			if (target >= nums[start] && target < nums[mid]) {
				end = mid - 1;
			} else {
				start = mid + 1;
			}
		} else {
			if (target > nums[mid] && target <= nums[end]) {
				start = mid + 1;
			} else {
				end = mid - 1;
			}
		}
	}
	return -1;
}

#include <Solution.h>
#include <iostream>

//[ 4, 5, 6, 7, 0 ,1 ,2 ]

int Solution::search4(vector<int> &nums, int target) {
	int l = 0, r = nums.size() - 1;
	int mid = 0;

	while (l <= r) {
		mid = (l + r) >> 1;
		if (nums[mid] == target) {
			return mid;
		} else if (nums[mid] < nums[r]) {
			if (nums[mid] < target && target <= nums[r]) {
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		} else {
			if (nums[mid] > target && target >= nums[l]) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
	}
	return -1;
}

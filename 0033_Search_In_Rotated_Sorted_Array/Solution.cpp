#include <Solution.h>
#include <iostream>

//[ 4, 5, 6, 7, 0 ,1 ,2 ]

int Solution::search(vector<int>& nums, int target) {
	int mid = -1, left  = 0 , right = nums.size() - 1;
	while (left <= right) {
		mid = (left + right) >> 1;
		if (nums[mid] == target) return mid;

		if (nums[left] <= nums[mid]) {
			if (target <= nums[mid] && target >= nums[left]) {
				right = mid - 1;
			} else {
				left = mid + 1;
			}
		} else {
			if (target >= nums[mid] && target <= nums[right]) {
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}
	}
	return -1;
}

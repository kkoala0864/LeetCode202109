#include <Solution.h>
#include <iostream>

int Solution::findMin(vector<int>& nums) {
	int start = 0, end = nums.size() - 1;
	int mid = 0;

	while ( start < end ) {
		mid = (end + start) / 2;
		if (nums[mid] > nums[end]) {
			start = mid + 1;
		} else if (nums[mid] < nums[end]) {
			end = mid;
		} else {
			--end;
		}
	}
	return nums[start];
}


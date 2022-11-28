#include <Solution.h>
#include <iostream>

int Solution::findPeakElement2(vector<int>& nums) {
	int l = 0, r = nums.size() - 1;
	int mid = 0;

	while (l < r) {
		mid = l + ((r-l) >> 1);
		if (nums[mid] > nums[mid+1]) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	return l;
}

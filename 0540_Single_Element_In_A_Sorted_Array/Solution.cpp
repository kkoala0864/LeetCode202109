#include <Solution.h>
#include <iostream>

int Solution::singleNonDuplicate(vector<int> &nums) {
	int start = 0;
	int end = nums.size() - 1;
	int mid = -1;
	while (start < end) {
		mid = (start + end) / 2;
		if (mid % 2 == 1)
			--mid;
		if (nums[mid] == nums[mid + 1]) {
			start = mid + 2;
		} else {
			end = mid;
		}
	}
	return nums[start];
}

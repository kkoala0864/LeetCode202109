#include <Solution.h>
#include <iostream>

int Solution::binary_search(vector<int> &nums, int target) {
	int l = 0, r = nums.size() - 1;
	int mid = -1;

	while (l < r) {
		mid = l + ((r - l) / 2);
		if (nums[mid] < target) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	return nums[l] == target ? l : -1;
}

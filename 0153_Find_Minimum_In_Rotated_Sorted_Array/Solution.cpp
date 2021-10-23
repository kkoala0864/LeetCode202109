#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;

int Solution::findMin(vector<int>& nums) {
	if (nums.size() == 1) return nums[0];
	int start = 0, end = nums.size() - 1;
	int mid = 0;

	while (start < end) {
		mid = (start+end) / 2;
		if (nums[start] < nums[end]) return nums[start];
		else if (nums[mid] > nums[end]) {
			start = mid + 1;
		} else {
			end = mid;
		}
	}
	return nums[start];
}

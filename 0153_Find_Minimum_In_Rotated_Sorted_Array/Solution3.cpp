#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;

int Solution::findMin3(vector<int> &nums) {
	int start = 0, end = nums.size() - 1;
	int mid = 0;
	while (start < end) {
		mid = (start + end) / 2;
		if (nums[mid] > nums[end]) {
			start = mid + 1;
		} else {
			end = mid;
		}
	}
	return nums[start];
}

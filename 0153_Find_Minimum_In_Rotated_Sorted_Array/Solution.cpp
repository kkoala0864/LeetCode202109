#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;

void BSearch(const vector<int>& nums, int start, int end, int& result) {
	if (end < start) return;
	if (nums[start] <= nums[end]) {
		result = nums[start];
		return;
	}

	if ((end - start + 1) == 2) {
		result = min(nums[start], nums[end]);
		return;
	}

	int mid = (end + start) / 2;

	if (nums[start] > nums[mid]) BSearch(nums, start, mid, result);
	else BSearch(nums, mid+1, end, result);
}

int Solution::findMin(vector<int>& nums) {
	int size = nums.size();
	int result = -1;
	BSearch(nums, 0, nums.size() - 1, result);
	return result;
}

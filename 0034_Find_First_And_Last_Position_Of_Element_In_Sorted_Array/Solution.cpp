#include <Solution.h>
#include <iostream>

int bsearch(const vector<int> &nums, int target) {
	int left = 0;
	int right = nums.size() - 1;
	int mid = 0;
	while (left <= right) {
		mid = (left + right) / 2;

		if (nums[mid] == target)
			return mid;
		else if (nums[mid] > target) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return -1;
}

vector<int> Solution::searchRange(vector<int> &nums, int target) {
	if (nums.empty())
		return vector<int>(2, -1);
	int idx = bsearch(nums, target);
	if (idx == -1)
		return vector<int>(2, -1);
	int left = idx, right = idx;
	while (left >= 0 && nums[left] == target)
		--left;
	while (right < nums.size() && nums[right] == target)
		++right;
	vector<int> result = {++left, --right};
	return result;
}

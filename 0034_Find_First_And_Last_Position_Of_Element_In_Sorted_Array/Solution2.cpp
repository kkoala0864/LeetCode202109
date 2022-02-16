#include <Solution.h>
#include <iostream>

int bs(const vector<int>& nums, int target) {
	int start = 0, end = nums.size() - 1;
	int mid = 0;
	while (start <= end) {
		mid = (start + end) / 2;
		if (nums[mid] == target) return mid;
		else if (nums[mid] > target) end = mid - 1;
		else start = mid + 1;
	}
	return -1;
}

vector<int> Solution::searchRange2(vector<int>& nums, int target) {
	if (nums.empty()) return {-1, -1};
	int idx = bs(nums, target);
	if (idx == -1) return {-1, -1};
	int start = idx, end = idx;
	while (start > 0 && nums[start] == nums[start-1]) --start;
	while (end < nums.size() - 1 && nums[end] == nums[end+1]) ++end;
	return {start, end};
}

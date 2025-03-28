#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int select(vector<int> &nums, int start, int end) {
	int pivot = nums[start];
	int l = start + 1;
	int r = end;

	while (l <= r) {
		while (l <= r && nums[l] <= pivot)
			++l;
		while (l <= r && nums[r] > pivot)
			--r;
		if (l < r)
			swap(nums[l], nums[r]);
	}
	swap(nums[start], nums[r]);
	return r;
}

int quickSelect(vector<int> &nums, int k, int start, int end) {
	if (start > end)
		return -1;
	int idx = -1;

	while (true) {
		idx = select(nums, start, end);
		if (idx == k - 1) {
			break;
		} else if (idx > (k - 1)) {
			end = idx - 1;
		} else
			start = idx + 1;
	}
	return nums[idx];
}

int Solution::quick_select(vector<int> &nums, int k) {
	return quickSelect(nums, k, 0, nums.size() - 1);
}

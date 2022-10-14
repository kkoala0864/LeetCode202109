#include <Solution.h>
#include <iostream>
using std::swap;

// quick select

int partition(vector<int>& nums, int left , int right) {
	int pivot = nums[left], l = left + 1, r = right;

	while (l <= r) {
		if (nums[l] < pivot && nums[r] > pivot) swap(nums[l], nums[r]);
		if (nums[l] >= pivot) ++l;
		if (nums[r] <= pivot) --r;
	}
	swap(nums[r], nums[left]);
	return r;
}


int Solution::findKthLargest3(vector<int>& nums, int k) {
	int left = 0, right = nums.size() - 1;
	int idx = 0;
	while (1) {
		idx = partition(nums, left, right);
		if (idx == k-1) break;
		else if (idx < k - 1) left = idx + 1;
		else right = idx - 1;
	}
	return nums[idx];
}

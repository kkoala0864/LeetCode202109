#include <Solution.h>
#include <iostream>

void quickSort(vector<int>& nums, int start, int end) {
	if (start >= end) return;
	int pivot = nums[start];
	int l = start + 1;
	int r = end;

	while (l <= r) {
		while (l <= r && nums[l] <= pivot) ++l;
		while (l <= r && nums[r] > pivot) --r;
		if (l < r) swap(nums[l], nums[r]);
	}

	swap(nums[start], nums[r]);
	quickSort(nums, start, r - 1);
	quickSort(nums, r + 1, end);
}

vector<int> Solution::Quick_Sort(vector<int>& nums) {
	quickSort(nums, 0, nums.size() - 1);
	return nums;
}

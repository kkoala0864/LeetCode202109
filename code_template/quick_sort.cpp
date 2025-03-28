#include <Solution.h>
#include <iostream>
#include <cmath>

void quickSort(vector<int> &nums, int start, int end) {
	if (start >= end)
		return;
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
	quickSort(nums, start, r - 1);
	quickSort(nums, r + 1, end);
}

void quickSort_Without_SwapPivot(vector<int> &nums, int start, int end) {
	if (start >= end)
		return;
	int pivot = nums[start + rand() % (end - start)];

	int l = start;
	int r = end;
	for (int i = start; i <= end; ++i) {
		if (nums[i] < pivot) {
			swap(nums[i], nums[l++]);
		}
	}
	for (int i = end; i >= l; --i) {
		if (nums[i] > pivot) {
			swap(nums[i], nums[r--]);
		}
	}
	quickSort_Without_SwapPivot(nums, start, l - 1);
	quickSort_Without_SwapPivot(nums, r + 1, end);
}

vector<int> Solution::quick_sort(vector<int> &nums) {
	quickSort_Without_SwapPivot(nums, 0, nums.size() - 1);
	return nums;
}

#include <Solution.h>
#include <iostream>

int findMinBigEqualThanMe(vector<int>& list, int val) {
	int start = 0, end = list.size() - 1;
	int mid = 0;
	while (start <= end) {
		mid = (end - start) / 2 + start;
		if (list[mid] < val) {
			start = mid + 1;
		} else {
			end = mid - 1;
		}
	}
	return start < list.size() && list[start] >= val ? start : -1;
}

vector<int> Solution::countSmaller(vector<int>& nums) {
	vector<int> result(nums.size(), 0);
	vector<int> list(1, nums.back());
	for (int i = nums.size() - 2 ; i >= 0 ; --i) {
		int idx = findMinBigEqualThanMe(list, nums[i]);
		result[i] = idx == -1 ? list.size() : idx;
		if (idx == -1)
			list.emplace_back(nums[i]);
		else
			list.insert(list.begin() + idx, nums[i]);
	}
	return result;
}

vector<int> Solution::SegTree(vector<int>& nums) {
	sTree t(2 * (1e4 + 1));
	for (int i = nums.size() - 1 ; i >= 0 ; --i) {
		t.update(nums[i] + (1e4+1));
		nums[i] = t.query(nums[i]+1e4);
	}
	return nums;
}

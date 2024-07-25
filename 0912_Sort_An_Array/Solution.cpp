#include <Solution.h>
#include <iostream>

// merge sort
using std::swap;
using std::cout;
using std::endl;

vector<int> mergeSort(vector<int>& nums, int start, int end) {
	if (start > end) return {};
	if (start == end) return {nums[start]};

	int mid = start + ((end - start) / 2);
	auto l = mergeSort(nums, start, mid);
	auto r = mergeSort(nums, mid + 1, end);
	vector<int> result;

	int li = 0, ri = 0;
	while (li < l.size() && ri < r.size()) {
		if (l[li] < r[ri]) {
			result.emplace_back(l[li++]);
		} else {
			result.emplace_back(r[ri++]);
		}
	}
	while (li < l.size()) result.emplace_back(l[li++]);
	while (ri < r.size()) result.emplace_back(r[ri++]);
	return result;
}

vector<int> Solution::sortArray(vector<int>& nums) {
	return mergeSort(nums, 0, nums.size() - 1);
}

#include <Solution.h>
#include <iostream>

vector<int> Solution::pivotArray(vector<int>& nums, int pivot) {
	vector<int> result(nums.size(), pivot);
	int equal = 0;
	int ri = 0;

	for (const auto& v : nums) {
		if (v < pivot) {
			result[ri++] = v;
		} else if (v == pivot) {
			++equal;
		}
	}
	ri += equal;
	for (const auto& v : nums) {
		if (v <= pivot) continue;
		result[ri++] = v;
	}
	return result;
}

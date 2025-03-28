#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;

int twoSumSmaller(vector<int> &nums, int start, int target) {
	int l = start, r = nums.size() - 1;
	int result = 0;

	while (l < r) {
		int v = nums[l] + nums[r];
		if (v < target) {
			result += (r - l);
			++l;
		} else {
			--r;
		}
	}
	return result;
}

int Solution::threeSumSmaller(vector<int> &nums, int target) {
	sort(nums.begin(), nums.end());
	int result = 0;
	int size = nums.size();

	for (int i = 0; i < size - 2; ++i) {
		result += twoSumSmaller(nums, i + 1, target - nums[i]);
	}
	return result;
}

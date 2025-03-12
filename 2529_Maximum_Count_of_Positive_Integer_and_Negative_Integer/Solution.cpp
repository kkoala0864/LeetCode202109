#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int Solution::maximumCount(vector<int>& nums) {
	int size = nums.size();
	int l = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
	if (l == nums.size()) {
		return l;
	}
	if (nums[l] != 0) {
		return max(l, size - l);
	}
	int r = upper_bound(nums.begin(), nums.end(), 0) - nums.begin();
	return max(l, size - r);
}

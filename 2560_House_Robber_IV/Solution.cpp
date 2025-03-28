#include <Solution.h>
#include <iostream>

bool check(vector<int> &nums, int c, int k) {
	int result = 0;

	for (int i = 0; i < nums.size(); ++i) {
		if (nums[i] > c)
			continue;
		++result;
		++i;
	}
	return result >= k;
}

int Solution::minCapability(vector<int> &nums, int k) {
	int l = 1, r = INT_MAX >> 1;
	int mid = 0;

	while (l < r) {
		mid = l + ((r - l) >> 1);

		if (check(nums, mid, k)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	return l;
}

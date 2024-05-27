#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;

int Solution::specialArray(vector<int>& nums) {
	sort(nums.begin(), nums.end());

	int l = 1, r = nums.size();
	int size = nums.size();

	while (l <= r) {
		int mid = l + ((r - l) / 2);
		int v = (lower_bound(nums.begin(), nums.end(), mid) - nums.begin());
		v = size - v;
		if (v > mid) {
			l = mid + 1;
		} else if (v == mid) {
			return mid;
		} else {
			r = mid - 1;
		}
	}
	return -1;
}

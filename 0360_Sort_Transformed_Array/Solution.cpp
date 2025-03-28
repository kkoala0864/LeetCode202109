#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::reverse;

vector<int> Solution::sortTransformedArray(vector<int> &nums, int a, int b, int c) {
	vector<int> tmp(nums.size(), c);

	for (int i = 0; i < nums.size(); ++i)
		tmp[i] += (nums[i] * b);
	int l = 0, r = nums.size() - 1;
	vector<int> result(nums.size(), 0);
	if (a >= 0) {
		int idx = nums.size() - 1;

		while (idx >= 0) {
			int lv = tmp[l] + (nums[l] * nums[l]) * a;
			int rv = tmp[r] + (nums[r] * nums[r]) * a;
			if (lv > rv) {
				result[idx] = lv;
				++l;
			} else {
				result[idx] = rv;
				--r;
			}
			--idx;
		}
	} else {
		int idx = 0;
		while (idx < nums.size()) {
			int lv = tmp[l] + (nums[l] * nums[l]) * a;
			int rv = tmp[r] + (nums[r] * nums[r]) * a;
			if (lv < rv) {
				result[idx] = lv;
				++l;
			} else {
				result[idx] = rv;
				--r;
			}
			++idx;
		}
	}
	return result;
}

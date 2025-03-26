#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int Solution::lengthOfLIS(vector<int>& nums, int k) {
	int mx = 0;
	for (const auto& v : nums) mx = max(mx, v);
	STree t(mx + 1);
	int sz = nums.size();

	int result = 0;
	for (const auto& v : nums) {
		int len = t.query(1, max(0, v - k), max(0, v - 1), 0, mx + 1);
		t.update(1, len + 1, v, 0, mx + 1);
		result = max(result, len + 1);
	}
	return result;
}

#include <Solution.h>
#include <iostream>

vector<int> Solution::majorityElement2(vector<int> &nums) {
	int val1 = INT_MAX;
	int val2 = INT_MAX;
	int cnt1 = 0;
	int cnt2 = 0;

	for (int i = 0; i < nums.size(); ++i) {
		if (val1 == nums[i]) {
			++cnt1;
		} else if (val2 == nums[i]) {
			++cnt2;
		} else if (cnt1 == 0) {
			val1 = nums[i];
			cnt1 = 1;
		} else if (cnt2 == 0) {
			val2 = nums[i];
			cnt2 = 1;
		} else {
			--cnt1;
			--cnt2;
		}
	}
	cnt1 = 0;
	cnt2 = 0;
	vector<int> result;
	for (const auto &v : nums) {
		if (v == val1)
			++cnt1;
		if (v == val2)
			++cnt2;
	}
	if (cnt1 > nums.size() / 3)
		result.emplace_back(val1);
	if (cnt2 > nums.size() / 3)
		result.emplace_back(val2);
	return result;
}

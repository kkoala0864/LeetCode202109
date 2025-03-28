#include <Solution.h>
#include <iostream>

vector<int> Solution::resultsArray(vector<int> &nums, int k) {
	int cnt = 1;
	vector<int> result;
	for (int i = 0; i < nums.size(); ++i) {
		if (i > 0 && nums[i] == (nums[i - 1] + 1)) {
			++cnt;
		} else {
			cnt = 1;
		}
		if (i >= k - 1) {
			if (cnt >= k)
				result.emplace_back(nums[i]);
			else
				result.emplace_back(-1);
		}
	}
	return result;
}

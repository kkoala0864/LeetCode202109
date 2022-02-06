#include <Solution.h>
#include <iostream>

int Solution::removeDuplicates3(vector<int>& nums) {
	if (nums.empty()) return 0;
	int idx = 1;
	int cur = nums[0], cnt = 1;
	for (int i = 1 ; i < nums.size() ; ++i) {
		if (nums[i] == cur) ++cnt;
		else {
			cur = nums[i];
			cnt = 1;
		}

		if (cnt > 2) continue;
		nums[idx] = cur;
		++idx;
	}
	return idx;
}

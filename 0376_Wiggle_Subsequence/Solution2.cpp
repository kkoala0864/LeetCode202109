#include <Solution.h>
#include <iostream>

int Solution::wiggleMaxLength2(vector<int>& nums) {
	if (nums.size() < 2) return nums.size();
	vector<int> diff;
	for (int i = 1 ; i < nums.size() ; ++i) {
		int val = nums[i] - nums[i-1];
		if (val != 0) diff.emplace_back(val);
	}

	if (diff.empty()) return 1;
	int cnt = 0;
	int i = 0;
	bool flip = diff[i] > 0;
	while (i < diff.size()) {
		if (flip) {
			while (i < diff.size() && diff[i] >= 0) ++i;
			flip = false;
		} else {
			while (i < diff.size() && diff[i] <= 0) ++i;
			flip = true;
		}
		++cnt;
	}
	return cnt + 1;
}

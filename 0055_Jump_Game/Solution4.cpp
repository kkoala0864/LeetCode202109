#include <Solution.h>
#include <iostream>
#include <algorithm>
using std::max;

bool Solution::canJump4(vector<int> &nums) {
	int maxIdx = nums[0];
	int i = 1;
	for (; i < nums.size() && i <= maxIdx; ++i) {
		maxIdx = max(maxIdx, i + nums[i]);
	}
	return i == nums.size();
}

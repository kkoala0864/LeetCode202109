#include <Solution.h>
#include <iostream>
#include <algorithm>
using std::max;

bool Solution::canJump3(vector<int> &nums) {
	int maxReach = nums[0];
	int i = 1;
	for (; i < nums.size() && i <= maxReach; ++i) {
		maxReach = max(maxReach, i + nums[i]);
	}
	return i == nums.size();
}

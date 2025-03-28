#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
using std::min;

bool Solution::canJump6(vector<int> &nums) {
	int maxStep = 0;
	for (int i = 0; i < nums.size() && i <= maxStep; ++i) {
		maxStep = max(maxStep, i + nums[i]);
		if (maxStep >= nums.size() - 1)
			return true;
	}
	return false;
}

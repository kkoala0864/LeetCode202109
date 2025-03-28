#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

bool Solution::canJump2(vector<int> &nums) {
	int size = nums.size();
	int maxReach(0);

	for (int i = 0; i < size && i <= maxReach; ++i) {
		maxReach = max(i + nums[i], maxReach);
		if (maxReach >= size - 1)
			return true;
	}
	return false;
}

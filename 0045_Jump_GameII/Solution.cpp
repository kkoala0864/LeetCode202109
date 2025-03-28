#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
using std::min;

int Solution::jump(vector<int> &nums) {
	int cnt = 0;
	int reach = 0;
	int maxReach = 0;
	for (int i = 0; i < nums.size() - 1; ++i) {
		maxReach = max(maxReach, i + nums[i]);

		if (i == reach) {
			++cnt;
			reach = maxReach;
		}
	}
	return cnt;
}

#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;
using std::max;

int Solution::jump(vector<int>& nums) {
	int cnt = -1;
	int reach = 0;
	int maxReach = 0;
	for (int i = 0 ; i < nums.size()-1 ; ++i) {
		maxReach = max(maxReach, i + nums[i]);

		if (i == reach) {
			++cnt;
			reach = maxReach;
		}
	}
	return cnt;
}

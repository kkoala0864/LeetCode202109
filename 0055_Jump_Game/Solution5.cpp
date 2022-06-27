#include <Solution.h>
#include <iostream>
#include <algorithm>
using std::max;
using std::min;

bool Solution::canJump5(vector<int>& nums) {
	int reach = 0;
	for (int i = 0 ; i <= min(reach, (int)nums.size()-1) ; ++i) {
		reach = max(reach, i + nums[i]);
		if (reach >= nums.size()-1) return true;
	}
	return false;
}

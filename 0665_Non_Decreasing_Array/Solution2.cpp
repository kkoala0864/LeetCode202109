#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

// 3 4 1
//
// 2 5 4
bool Solution::checkPossibility2(vector<int>& nums) {
	int err = 0;
	for (int i = 0 ; i < nums.size() - 1 ; ++i) {
		if (nums[i] > nums[i+1]) {
			if (err > 0) return false;
			++err;
			if (i-1 >= 0 && nums[i-1] > nums[i+1])
				nums[i+1] = nums[i];
			else
				nums[i] = nums[i+1];
		}
	}
	return true;
}

#include <Solution.h>
#include <iostream>

int Solution::majorityElement2(vector<int>& nums) {
	int val = 0;
	int cnt = 0;
	for (int i = 0 ; i < nums.size() ; ++i) {
		if (cnt == 0) {
			val = nums[i];
			cnt = 1;
		} else {
			if (val == nums[i]) {
				++cnt;
			} else {
				--cnt;
			}
		}
	}
	return val;
}

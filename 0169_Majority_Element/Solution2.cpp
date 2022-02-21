#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

int Solution::majorityElement2(vector<int>& nums) {
	int i = 0;
	int iter = 0;
	int cur = 0;
	while (iter < nums.size()) {
		if (i == 0) {
			cur = nums[iter];
			i = 1;
		} else {
			if (cur == nums[iter]) {
				++i;
			} else {
				--i;
			}
		}
		++iter;
	}
	return cur;
}

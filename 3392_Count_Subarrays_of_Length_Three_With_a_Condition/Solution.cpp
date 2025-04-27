#include <Solution.h>
#include <iostream>

int Solution::countSubarrays(vector<int>& nums) {
	// 0 1 2 3 4
	int result = 0;
	for (int i = 0 ; i < nums.size() - 2 ; ++i) {
		double m = (double)nums[i+1] / 2;
		if (double(nums[i] + nums[i+2]) == m) ++result;
	}
	return result;
}

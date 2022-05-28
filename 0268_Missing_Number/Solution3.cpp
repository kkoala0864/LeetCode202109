#include <Solution.h>
#include <iostream>

int Solution::missingNumber3(vector<int>& nums) {
	int result = nums.size() * (nums.size()+1) / 2;
	for (const auto& val : nums) {
		result -= val;
	}
	return result;
}

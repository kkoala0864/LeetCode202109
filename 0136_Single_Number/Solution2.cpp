#include <Solution.h>
#include <iostream>

int Solution::singleNumber2(vector<int> &nums) {
	int result = nums[0];
	for (int i = 1; i < nums.size(); ++i) {
		result ^= nums[i];
	}
	return result;
}

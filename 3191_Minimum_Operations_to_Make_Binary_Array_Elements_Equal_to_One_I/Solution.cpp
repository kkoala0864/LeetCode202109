#include <Solution.h>
#include <iostream>


// 0 1 2 3 4
int Solution::minOperations(vector<int>& nums) {

	int result = 0;
	for (int i = 0 ; i < nums.size() - 2 ; ++i) {
		if (nums[i]) continue;
		for (int j = 0 ; j < 3 ; ++j) {
			nums[i+j] = nums[i+j] == 0 ? 1 : 0;
		}
		++result;
	}

	if (nums.back() != 1 || nums[nums.size() - 2] != 1) return -1;
	return result;
}

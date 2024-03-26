#include <Solution.h>
#include <iostream>

int Solution::firstMissingPositive2(vector<int>& nums) {
	int size = nums.size();
	for (int i = 0 ; i < nums.size() ; ++i) {
		if (nums[i] <= 0) nums[i] = size + 1;
	}
	for (int i = 0 ; i < nums.size() ; ++i) {
		if (nums[i] == 0) continue;
		if (abs(nums[i]) > size) continue;
		if (nums[abs(nums[i])-1] < 0) continue;
		nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
	}
	for (int i = 0 ; i < nums.size() ; ++i) {
		if (nums[i] > 0) return i + 1;
	}
	return size + 1;
}

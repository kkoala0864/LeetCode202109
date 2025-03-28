#include <Solution.h>
#include <iostream>

vector<int> Solution::runningSum(vector<int> &nums) {
	for (int i = 1; i < nums.size(); ++i) {
		nums[i] += nums[i - 1];
	}
	return nums;
}

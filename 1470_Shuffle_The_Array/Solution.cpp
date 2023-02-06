#include <Solution.h>
#include <iostream>

vector<int> Solution::shuffle(vector<int>& nums, int n) {
	vector<int> result(nums.size(), 0);

	for (int i = 0 ; i < n ; ++i) {
		result[2 * i] = nums[i];
		result[2 * i + 1] = nums[i + n];
	}
	return result;
}

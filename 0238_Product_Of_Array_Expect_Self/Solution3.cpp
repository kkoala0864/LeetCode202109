#include <Solution.h>
#include <iostream>

vector<int> Solution::productExceptSelf3(vector<int> &nums) {
	vector<int> result(nums.size(), 1);

	int product = 1;
	for (int i = 0; i < nums.size() - 1; ++i) {
		product = product * nums[i];
		result[i + 1] = product;
	}
	product = 1;
	for (int i = nums.size() - 1; i > 0; --i) {
		product = product * nums[i];
		result[i - 1] *= product;
	}
	return result;
}

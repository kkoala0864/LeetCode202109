#include <Solution.h>
#include <iostream>

int Solution::numSubarrayProductLessThanK(vector<int>& nums, int k) {
	int product = 1;
	int l = 0;
	int result = 0;
	for (int i = 0 ; i < nums.size() ; ++i) {
		product *= nums[i];

		while (l <= i && product >= k) {
			product /= nums[l++];
		}
		result += (i - l + 1);
	}
	return result;
}

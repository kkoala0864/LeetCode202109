#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::max;

int Solution::maxProduct(vector<int>& nums) {
	int m = nums[0];
	int result = INT_MIN;

	for (int i = 1 ; i < nums.size() ; ++i) {
		result = max(result, (m - 1) * (nums[i] - 1));
		m = max(m, nums[i]);
	}
	return result;
}

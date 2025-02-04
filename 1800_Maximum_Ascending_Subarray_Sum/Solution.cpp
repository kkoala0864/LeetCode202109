#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int Solution::maxAscendingSum(vector<int>& nums) {
	int result = nums[0];
	int sum = nums[0];
	for (int i = 1 ; i < nums.size() ; ++i) {
		if (nums[i] <= nums[i-1]) {
			sum = 0;
		}
		sum += nums[i];
		result = max(result, sum);
	}
	return result;

}

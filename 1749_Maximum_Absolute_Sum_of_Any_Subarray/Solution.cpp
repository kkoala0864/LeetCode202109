#include <Solution.h>
#include <iostream>
#include <cmath>
#include <algorithm>

using std::max;
using std::min;

//kadane algorithm
int Solution::maxAbsoluteSum(vector<int>& nums) {
	int minV = nums[0];
	int maxV = nums[0];

	int result = abs(nums[0]);
	int sum = nums[0];
	for (int i = 1 ; i < nums.size() ; ++i) {
		sum += nums[i];
		if (sum < 0) {
			result = max(result, abs(sum - maxV));
		} else {
			result = max(result, abs(sum - minV));
		}
		result = max(result, abs(sum));
		minV = min(minV, sum);
		maxV = max(maxV, sum);
	}
	return result;
}

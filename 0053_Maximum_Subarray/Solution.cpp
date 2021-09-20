#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::max;

int Solution::maxSubArray(vector<int>& nums) {
	int n = nums.size();
	int maxVal = INT_MIN;

	int localVal = 0;
	for (int i = 0 ; i < n ; ++i) {
		localVal += nums[i];
		maxVal = max(maxVal, localVal);
		if (localVal < 0) localVal = 0;
	}

	return maxVal;
}

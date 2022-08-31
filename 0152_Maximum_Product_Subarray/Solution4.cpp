#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
using std::min;

int Solution::maxProduct4(vector<int>& nums) {
	int maxVal = 1;
	int minVal = 1;
	int result = INT_MIN;

	for (int i = 0 ; i < nums.size() ; ++i) {
		int lastMax = maxVal;
		maxVal = max({maxVal * nums[i], minVal * nums[i], nums[i]});
		minVal = min({lastMax * nums[i], minVal * nums[i], nums[i]});
		result = max(maxVal, result);
	}
	return result;
}

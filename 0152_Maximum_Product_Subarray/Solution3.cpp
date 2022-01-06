#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
using std::min;

int Solution::maxProduct3(vector<int>& nums) {
	int minVal = nums[0];
	int maxVal = nums[0];
	int result = nums[0];

	for (int i = 1 ; i < nums.size() ; ++i) {
		int tmpMax = max({minVal * nums[i], maxVal * nums[i], nums[i]});
		minVal = min({minVal * nums[i], maxVal * nums[i], nums[i]});
		maxVal = tmpMax;
		result = max(result, maxVal);
	}
	return result;
}

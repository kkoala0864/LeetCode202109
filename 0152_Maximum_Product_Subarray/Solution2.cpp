#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
using std::min;

int Solution::maxProduct2(vector<int> &nums) {
	int minVal = nums[0];
	int maxVal = nums[0];
	int result = nums[0];

	for (int i = 1; i < nums.size(); ++i) {
		int tmpMax = max({maxVal * nums[i], minVal * nums[i], nums[i]});
		minVal = min({maxVal * nums[i], minVal * nums[i], nums[i]});
		maxVal = tmpMax;
		result = max(result, maxVal);
	}
	return result;
}

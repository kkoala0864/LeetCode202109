#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::max;
using std::min;

int Solution::maxProduct5(vector<int> &nums) {
	int minVal = 1;
	int maxVal = 1;
	int result = INT_MIN;
	for (const auto &n : nums) {
		int tmpMax = maxVal;
		maxVal = max({maxVal * n, minVal * n, n});
		minVal = min({minVal * n, tmpMax * n, n});
		result = max(maxVal, result);
	}
	return result;
}

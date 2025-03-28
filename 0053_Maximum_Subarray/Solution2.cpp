#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::max;

int Solution::maxSubArray2(vector<int> &nums) {
	int result = INT_MIN;
	int sum = 0;
	for (const auto &iter : nums) {
		sum += iter;
		result = max(sum, result);
		if (sum < 0)
			sum = 0;
	}
	return result;
}

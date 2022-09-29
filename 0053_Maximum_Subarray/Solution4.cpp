#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::max;

int Solution::maxSubArray4(vector<int>& nums) {
	int result = INT_MIN;
	int sum = 0;
	for (const auto& n : nums) {
		sum += n;
		result = max(result, sum);
		if (sum < 0) sum = 0;
	}
	return result;
}

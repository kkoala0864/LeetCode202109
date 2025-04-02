#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

long long Solution::maximumTripletValue(vector<int> &nums) {
	vector<long long> maxDiff(nums.size(), LLONG_MIN);

	long long maxVal = nums[0];
	long long minVal = nums[0];
	for (int i = 1; i < nums.size(); ++i) {
		maxVal = max(maxVal, (long long)nums[i]);
		minVal = min(maxVal, (long long)nums[i]);
		maxDiff[i] = max(maxDiff[i - 1], maxVal - minVal);
	}

	vector<long long> postMax(nums.size(), LLONG_MIN);
	postMax.back() = nums.back();
	for (int i = nums.size() - 2; i >= 0; --i) {
		postMax[i] = max(postMax[i + 1], (long long)nums[i]);
	}
	long long result = LLONG_MIN;
	for (int i = 1; i < nums.size() - 1; ++i) {
		result = max(result, maxDiff[i] * postMax[i + 1]);
	}
	return result;
}

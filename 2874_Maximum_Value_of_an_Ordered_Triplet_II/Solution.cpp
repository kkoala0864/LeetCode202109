#include <Solution.h>
#include <iostream>
#include <climits>
#include <algorithm>

using std::cout;
using std::endl;

long long Solution::maximumTripletValue(vector<int>& nums) {
	vector<long long> postMax(nums.size(), LLONG_MIN);

	postMax.back() = nums.back();
	for (int i = nums.size() - 2 ; i >= 0 ; --i) {
		postMax[i] = max(postMax[i+1], (long long)nums[i]);
	}

	long long maxVal = nums[0];
	long long maxDiff = LLONG_MIN;
	long long result = LLONG_MIN;

	for (int i = 1 ; i < nums.size() - 1 ; ++i) {
		maxVal = max(maxVal, (long long)nums[i]);
		maxDiff = max(maxDiff, maxVal - nums[i]);
		result = max(result, maxDiff * postMax[i+1]);
	}
	return result;
}

#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;

int Solution::minimumSum(vector<int>& nums) {
	vector<int> preMin(nums.size(), INT_MAX);
	vector<int> postMin(nums.size(), INT_MAX);

	int preVal = INT_MAX;
	int postVal = INT_MAX;

	for (int i = 0 ; i < nums.size() ; ++i) {
		preVal = min(preVal, nums[i]);
		postVal = min(postVal, nums[nums.size() - 1 - i]);
		preMin[i] = preVal;
		postMin[nums.size() - i - 1] = postVal;
	}

	int result = INT_MAX;
	for (int i = 1 ; i < nums.size() - 1 ; ++i) {
		if (preMin[i-1] < nums[i] && postMin[i+1] < nums[i]) {
			result = min(result, preMin[i-1] + nums[i] + postMin[i+1]);
		}
	}
	return result == INT_MAX ? -1 : result;
}

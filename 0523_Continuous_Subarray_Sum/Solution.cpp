#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

bool Solution::checkSubarraySum(vector<int>& nums, int k) {
	int curSum = 0;
	unordered_map<int, int> sumToIdx;
	sumToIdx[0] = 0;

	for (int i = 0 ; i < nums.size() ; ++i) {
		curSum += nums[i];
		if (sumToIdx.find(curSum % k) != sumToIdx.end()) {
			if (sumToIdx[curSum % k] < i) return true;
		} else {
			sumToIdx[curSum % k] = i + 1;
		}

	}
	return false;
}

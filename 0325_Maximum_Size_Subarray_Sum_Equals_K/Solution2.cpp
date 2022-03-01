#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using std::max;
using std::unordered_map;

int Solution::maxSubArrayLen2(vector<int>& nums, int k) {
	unordered_map<int, int> uMap;

	int accumulate = 0;
	int result = 0;
	for (int i = 0 ; i < nums.size() ; ++i) {
		accumulate += nums[i];
		if (uMap.find(accumulate) == uMap.end()) {
			uMap[accumulate] = i;
		}
		if (accumulate == k) result = max(result, i + 1);
		else {
			if (uMap.find(accumulate - k) != uMap.end()) {
				result = max(result, i - uMap[accumulate-k]);
			}
		}
	}
	return result;
}

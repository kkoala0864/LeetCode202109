#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using std::max;
using std::unordered_set;

int Solution::maximumUniqueSubarray(vector<int>& nums) {
	int result = 0;
	int l = 0;
	unordered_set<int> uSet;
	int local = 0;
	for (int i = 0 ; i < nums.size() ; ++i) {
		while (l < i && uSet.find(nums[i]) != uSet.end()) {
			uSet.erase(nums[l]);
			local -= nums[l++];
		}
		local += nums[i];
		uSet.emplace(nums[i]);
		result = max(result, local);
	}
	return result;
}

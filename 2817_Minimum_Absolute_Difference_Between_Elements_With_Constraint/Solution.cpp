#include <Solution.h>
#include <iostream>
#include <map>
#include <algorithm>

using std::map;
using std::min;

int Solution::minAbsoluteDifference(vector<int>& nums, int x) {
	if (x == 0) return 0;
	map<int, int> m;
	int result = INT_MAX;

	for (int i = x - 1 ; i < nums.size() ; ++i) {
		++m[nums[i]];
	}

	for (int i = 0 ; i < nums.size() ; ++i) {
		if (i >= x) {
			++m[nums[i-x]];
		}
		if ((i + x - 1) < nums.size()) {
			--m[nums[i+x-1]];
			if (m[nums[i+x-1]] == 0) m.erase(nums[i+x-1]);
		}

		auto iter = m.lower_bound(nums[i]);
		if (iter != m.end() && abs(nums[i] - iter->first) < result) {
			result = min(result, abs(nums[i] - iter->first));
		}

		iter = m.lower_bound(nums[i]);
		if (iter != m.begin()) {
			--iter;
			result = min(result, abs(nums[i] - iter->first));
		}
	}
	return result;
}

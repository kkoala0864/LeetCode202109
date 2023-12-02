#include <Solution.h>
#include <iostream>
#include <set>
#include <algorithm>

using std::set;
using std::max;

int Solution::twoSumLessThanK(vector<int>& nums, int k) {
	set<int> s;
	s.emplace(nums[0]);

	int result = INT_MIN;
	for (int i = 1 ; i < nums.size() ; ++i) {
		auto iter = s.lower_bound(k - nums[i]);

		if (iter != s.begin()) {
			--iter;
			result = max(result, *iter + nums[i]);
		}

		s.emplace(nums[i]);
	}
	return result == INT_MIN ? -1 : result;
}


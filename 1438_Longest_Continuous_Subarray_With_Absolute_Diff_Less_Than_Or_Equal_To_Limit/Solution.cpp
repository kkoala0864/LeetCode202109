#include <Solution.h>
#include <iostream>
#include <map>
#include <algorithm>

using std::map;
using std::max;

int Solution::longestSubarray(vector<int> &nums, int limit) {
	map<int, int> m;

	int l = 0;
	int result = 0;
	for (int i = 0; i < nums.size(); ++i) {
		++m[nums[i]];

		while ((m.rbegin()->first - m.begin()->first) > limit) {
			--m[nums[l]];
			if (m[nums[l]] == 0)
				m.erase(nums[l]);
			++l;
		}
		result = max(result, i - l + 1);
	}
	return result;
}

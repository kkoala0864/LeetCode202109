#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;

long long Solution::countFairPairs(vector<int>& nums, int lower, int upper) {
	long long result = 0;
	sort(nums.begin(), nums.end());

	for (int i = 1 ; i < nums.size() ; ++i) {
		int lv = lower - nums[i];
		int li = lower_bound(nums.begin(), nums.begin() + i, lv) - nums.begin();
		if (li == i) continue;

		int uv = upper - nums[i];
		int ui = upper_bound(nums.begin(), nums.begin() + i, uv) - nums.begin();
		if (ui == 0) continue;
		--ui;
		result += (ui - li + 1);
	}
	return result;
}


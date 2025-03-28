#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;

int Solution::minMoves2(vector<int> &nums) {
	sort(nums.begin(), nums.end());
	int mediumIdx = nums.size() / 2;
	int result = 0;
	for (const auto &v : nums)
		result += abs(v - nums[mediumIdx]);
	return result;
}

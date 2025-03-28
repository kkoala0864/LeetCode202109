#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::min;
using std::sort;

int Solution::minDifference(vector<int> &nums) {
	if (nums.size() <= 4)
		return 0;

	sort(nums.begin(), nums.end());

	int result = INT_MAX;
	int size = nums.size();
	for (int i = 0; i <= 3; ++i) {
		int l = nums[i];
		int r = nums[size - 1 - (3 - i)];
		result = min(result, r - l);
	}
	return result;
}

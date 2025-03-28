#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int Solution::longestNiceSubarray(vector<int> &nums) {
	int bitmask = 0;

	int l = 0;
	int result = 1;
	for (int i = 0; i < nums.size(); ++i) {
		while (bitmask & nums[i]) {
			bitmask = bitmask & ~nums[l++];
		}
		bitmask = bitmask | nums[i];
		result = max(result, i - l + 1);
	}
	return result;
}

#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

// kadane's algorithm
int Solution::longestSubarray(vector<int> &nums) {
	int curMax = 0;
	int maxLen = 0;

	int i = 0;
	while (i < nums.size()) {
		int cur = nums[i];
		int cnt = 0;
		int j = i;

		for (; j < nums.size() && cur == nums[j]; ++j) {
			++cnt;
		}
		i = j;
		if (cur == curMax) {
			maxLen = max(cnt, maxLen);
		} else if (cur > curMax) {
			maxLen = cnt;
			curMax = cur;
		}
	}
	return maxLen;
}

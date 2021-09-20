#include <Solution.h>
#include <iostream>
#include <algorithm>
using std::max;
/*
bool Solution::canJump(vector<int>& nums) {
	int size = nums.size();
	vector<bool> dp(size, false);

	for (int i = 0 ; i < size ; ++i) dp[i] = (nums[i]+i) >= (size - 1);

	while (true) {
		bool flip = false;
		for (int i = size - 2 ; i >= 0 ; --i) {
			if (dp[i]) continue;
			for (int j = 1 ; j <= nums[i] ; ++j) {
				if (dp[i+j]) {
					dp[i] = true;
					flip = true;
					break;
				}
			}
		}
		if (!flip) break;
	}
	return dp[0];
}
*/
bool Solution::canJump(vector<int>& nums) {
	int i = 0, reach = 0, size = nums.size();
	vector<int> dp(size, 0);

	for (; i < size && i <= reach ; ++i) {
		reach = max(i + nums[i], reach);
		if (reach >= (size-1)) return true;
	}
	return false;
}


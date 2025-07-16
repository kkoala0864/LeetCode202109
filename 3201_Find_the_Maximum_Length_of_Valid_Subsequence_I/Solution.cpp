#include <Solution.h>

int Solution::maximumLength(vector<int>& nums) {
	int odd = 0, even = 0, alter = 1;
	for (int i = 0 ; i < nums.size() ; ++i) {
		if (nums[i] & 1) ++odd;
		else ++even;

		if (i >= 1) {
			if ((nums[i] & 1) != (nums[i-1] & 1)) ++alter;
		}
	}
	return max({odd, even, alter});
}

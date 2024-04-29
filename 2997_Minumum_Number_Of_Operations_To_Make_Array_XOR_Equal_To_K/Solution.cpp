#include <Solution.h>
#include <iostream>

int Solution::minOperations(vector<int>& nums, int k) {
	int v = 0;

	for (int i = 0 ; i < nums.size() ; ++i) {
		v = v ^ nums[i];
	}

	int result = 0;
	for (int j = 0 ; j < 32 ; ++j) {
		int mask = 1 << j;
		if ((v & mask) == (k & mask)) continue;
		++result;
	}
	return result;
}

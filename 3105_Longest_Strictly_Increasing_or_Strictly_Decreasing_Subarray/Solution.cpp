#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int Solution::longestMonotonicSubarray(vector<int> &nums) {
	int il = 1;
	int dl = 1;
	int result = 1;
	for (int i = 1; i < nums.size(); ++i) {
		if (nums[i] > nums[i - 1]) {
			++il;
			dl = 1;
			result = max(result, il);
		} else if (nums[i] == nums[i - 1]) {
			il = 1;
			dl = 1;
		} else {
			++dl;
			il = 1;
			result = max(result, dl);
		}
	}

	return result;
}

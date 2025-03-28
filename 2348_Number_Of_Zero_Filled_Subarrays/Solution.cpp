#include <Solution.h>
#include <iostream>

long long Solution::zeroFilledSubarray(vector<int> &nums) {
	long long result = 0;
	long long zeroCnt = 0;

	for (int i = 0; i < nums.size(); ++i) {
		if (nums[i] == 0) {
			++zeroCnt;
			continue;
		}

		result += ((1 + zeroCnt) * zeroCnt / 2);
		zeroCnt = 0;
	}
	if (zeroCnt > 0) {
		result += ((1 + zeroCnt) * zeroCnt / 2);
	}
	return result;
}

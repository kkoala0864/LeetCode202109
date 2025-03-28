#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int Solution::maxSumAfterOperation(vector<int> &nums) {
	int change = 0;
	int notchange = 0;

	int cc = 0;
	int cn = 0;
	int result = INT_MIN;
	for (int i = 0; i < nums.size(); ++i) {
		cc = max(change + nums[i], notchange + (nums[i] * nums[i]));
		cn = notchange + nums[i];
		result = max({result, cc, cn});
		// if prefix is negative, we don't take
		change = max(cc, 0);
		notchange = max(cn, 0);
	}
	return result;
}

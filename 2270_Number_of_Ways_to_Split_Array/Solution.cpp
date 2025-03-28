#include <Solution.h>
#include <iostream>

int Solution::waysToSplitArray(vector<int> &nums) {
	long long sum = 0;
	for (const auto &v : nums)
		sum += (long long)v;
	int result = 0;
	long long cur = 0;
	for (int i = 0; i < nums.size() - 1; ++i) {
		cur += (long long)nums[i];
		if (cur >= (sum - cur))
			++result;
	}
	return result;
}

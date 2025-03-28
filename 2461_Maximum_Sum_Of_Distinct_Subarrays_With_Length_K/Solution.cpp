#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using std::max;
using std::unordered_map;

long long Solution::maximumSubarraySum(vector<int> &nums, int k) {
	long long result = 0;
	long long curSum = 0;
	int dupCnt = 0;
	unordered_map<int, int> m;

	for (int i = 0; i < nums.size(); ++i) {
		curSum += (long long)nums[i];
		++m[nums[i]];
		if (m[nums[i]] == 2)
			++dupCnt;

		if (i >= k) {
			curSum -= (long long)nums[i - k];
			--m[nums[i - k]];
			if (m[nums[i - k]] == 1)
				--dupCnt;
		}
		if (i >= k - 1 && dupCnt == 0) {
			result = max(result, curSum);
		}
	}
	return result;
}

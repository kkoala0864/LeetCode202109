#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

long long Solution::findMaximumScore(vector<int>& nums) {
	long long result = 0;
	long long cur = nums[0];
	for (int i = 1 ; i < nums.size() ; ++i) {
		result += cur;
		cur = max(cur, (long long)nums[i]);
	}

	return result;
}

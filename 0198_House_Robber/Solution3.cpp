#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
using std::swap;

int Solution::rob3(vector<int> &nums) {
	int prev = 0;
	int cur = nums[0];
	for (int i = 1; i < nums.size(); ++i) {
		prev = max(prev + nums[i], cur);
		swap(prev, cur);
	}
	return cur;
}

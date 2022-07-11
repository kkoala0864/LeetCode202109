#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::reverse;
using std::swap;

void Solution::rotate2(vector<int>& nums, int k) {
	int n = nums.size();
	k %= n;

	reverse(nums.begin(), nums.end() - k);
	reverse(nums.end() - k, nums.end());
	reverse(nums.begin(), nums.end());
}

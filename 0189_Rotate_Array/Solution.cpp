#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::swap;
using std::reverse;

void Solution::rotate(vector<int>& nums, int k) {
	if ((k % nums.size()) == 0) return;
	k = k % nums.size();
	reverse(nums.begin(), nums.end());
	reverse(nums.begin(), nums.begin() + k);
	reverse(nums.begin() + k, nums.end());
}

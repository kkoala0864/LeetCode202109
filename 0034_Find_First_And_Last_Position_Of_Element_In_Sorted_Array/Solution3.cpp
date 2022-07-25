#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::upper_bound;
using std::lower_bound;

vector<int> Solution::searchRange3(vector<int>& nums, int target) {
	if (nums.empty()) return {-1, -1};
	auto lb = lower_bound(nums.begin(), nums.end(), target);
	if (lb == nums.end() || *lb != target) return {-1, -1};
	auto ub = upper_bound(nums.begin(), nums.end(), target);
	int li = distance(nums.begin(), lb);
	int ui = distance(nums.begin(), ub);
	return {li, ui-1};
}
